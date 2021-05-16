#include <iostream>
using namespace std;
void merge(int M, int N, int A[], int B[]){
 
    for (int i = 0; i < M; i++)
    {
        if (A[i] > B[0])
        {
            swap(A[i], B[0]);
            int j = 0;
 
            while (j + 1 < N && B[j] > B[j + 1])
                swap(B[j], B[j + 1]), j++;
        }
    }
 
    for (int i = 0; i < M; i++)
        cout << A[i]<<"\t";
 
    cout << endl;
 
    for (int i = 0; i < N; i++)
        cout << B[i]<<"\t";
}
 
int main() {
	int M, N;
    cin >> M; 
    cin >> N;
 
    int A[M], B[N];
 
    for (int i = 0; i < M; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
 
    merge(M, N, A, B);
 
	return 0;
}