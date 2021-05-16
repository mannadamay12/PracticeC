#include <iostream>
using namespace std;
void max(int arr[], int n){
    int temp=0;
	for (int i=0; i<=n-1; i++){
	    for (int j=i+1; j<n; j++){
	    	if (arr[i] > arr[j]){  
                temp = arr[i];  
                arr[i] = arr[j];  
                arr[j] = temp;  
            }  
        }  
    }  
}
 
int main(){
    int n, k;
    cin>>n;
	int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }
	cin>>k;
	max(arr, n);
	cout<<k<<"th largest element in the given array is "<<arr[n-k+1]<<endl;
	cout<<k<<"th smallest element in the given array is "<<arr[k-1];
    return 0;
}