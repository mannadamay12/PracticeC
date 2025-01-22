#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdbool.h>

#define NUM_PROCS 4  // Number of worker processes
#define NUM_TRIALS 1000000  // Number of trials per process
#define DAYS_IN_YEAR 365

// Function to check if any birthdays match in an array
bool has_birthday_match(int birthdays[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (birthdays[i] == birthdays[j]) {
                return true;
            }
        }
    }
    return false;
}

// Function to perform Monte Carlo simulation
int run_simulation(int n) {
    int nhits = 0;  // Non-shared variable for counting matches
    int *birthdays = malloc(n * sizeof(int));
    
    for (int trial = 0; trial < NUM_TRIALS; trial++) {
        // Generate n random birthdays between 0 and 364
        for (int i = 0; i < n; i++) {
            birthdays[i] = rand() % DAYS_IN_YEAR;
        }
        
        if (has_birthday_match(birthdays, n)) {
            nhits++;
        }
    }
    
    free(birthdays);
    return nhits;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <class_size>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);  // Class size parameter
    int pipes[NUM_PROCS][2];  // Array of pipes for daisy chain
    pid_t pids[NUM_PROCS];    // Array to store child process IDs

    // Create pipes for daisy chain
    for (int i = 0; i < NUM_PROCS; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            return 1;
        }
    }

    // Create worker processes
    for (int i = 0; i < NUM_PROCS; i++) {
        pids[i] = fork();
        
        if (pids[i] < 0) {
            perror("fork");
            return 1;
        }
        
        if (pids[i] == 0) {  // Child process
            // Set different random seed for each process
            srand(time(NULL) ^ getpid());
            
            // Close unused pipes
            for (int j = 0; j < NUM_PROCS; j++) {
                if (j != i && j != (i-1)) {
                    close(pipes[j][0]);
                }
                if (j != i) {
                    close(pipes[j][1]);
                }
            }

            // Do simulation first (as required)
            int local_hits = run_simulation(n);
            int total_hits = local_hits;

            // If not first process, read from previous pipe
            if (i > 0) {
                int prev_hits;
                read(pipes[i-1][0], &prev_hits, sizeof(int));
                total_hits += prev_hits;
                close(pipes[i-1][0]);
            }

            // Write total to next process
            write(pipes[i][1], &total_hits, sizeof(int));
            close(pipes[i][1]);
            
            exit(0);
        }
    }

    // Parent process
    // Close all pipes except last read pipe
    for (int i = 0; i < NUM_PROCS; i++) {
        if (i != NUM_PROCS-1) {
            close(pipes[i][0]);
        }
        close(pipes[i][1]);
    }

    // Read final result from last pipe
    int total_hits;
    read(pipes[NUM_PROCS-1][0], &total_hits, sizeof(int));
    close(pipes[NUM_PROCS-1][0]);

    // Wait for all children
    for (int i = 0; i < NUM_PROCS; i++) {
        wait(NULL);
    }

    // Calculate and print probability
    double probability = (double)total_hits / (NUM_PROCS * NUM_TRIALS);
    printf("For class size %d:\n", n);
    printf("Total hits: %d\n", total_hits);
    printf("Probability: %.2f%%\n", probability * 100);

    return 0;
}