#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdbool.h>

#define NUM_PROCS 4  
#define NUM_TRIALS 1000000
#define DAYS_IN_YEAR 365

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

int run_simulation(int n) {
    int nhits = 0;
    int *birthdays = malloc(n * sizeof(int));
    
    for (int trial = 0; trial < NUM_TRIALS; trial++) {
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

    int n = atoi(argv[1]);
    int pipes[NUM_PROCS][2];
    pid_t child_pids[NUM_PROCS];

    for (int i = 0; i < NUM_PROCS; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            return 1;
        }
    }

    for (int child_num = 1; child_num <= NUM_PROCS; child_num++) {
        pid_t pid = fork();
        
        if (pid < 0) {
            perror("fork");
            return 1;
        }
        
        if (pid == 0) {
            int my_num = child_num;
            srand(time(NULL) ^ getpid());
            
            for (int p = 0; p < NUM_PROCS; p++) {
                if (p == my_num - 2) {
                    if (my_num != 1) {
                        continue;
                    }
                }
                if (p == my_num - 1) {
                    continue;
                }
                close(pipes[p][0]);
                close(pipes[p][1]);
            }

            int local_hits = run_simulation(n);
            int total_hits = local_hits;

            if (my_num > 1) {
                int prev_hits;
                read(pipes[my_num-2][0], &prev_hits, sizeof(int));
                close(pipes[my_num-2][0]);
                total_hits += prev_hits;
            }

            write(pipes[my_num-1][1], &total_hits, sizeof(int));
            close(pipes[my_num-1][1]);
            exit(0);
        }
        child_pids[child_num-1] = pid;
    }

    for (int i = 0; i < NUM_PROCS; i++) {
        if (i != NUM_PROCS-1) {
            close(pipes[i][0]);
        }
        close(pipes[i][1]);
    }

    int total_hits;
    read(pipes[NUM_PROCS-1][0], &total_hits, sizeof(int));
    close(pipes[NUM_PROCS-1][0]);

    for (int i = 0; i < NUM_PROCS; i++) {
        waitpid(child_pids[i], NULL, 0);
    }

    double probability = (double)total_hits / (NUM_PROCS * NUM_TRIALS);
    printf("For class size %d: Probability = %.2f%%\n", n, probability * 100);

    return 0;
}