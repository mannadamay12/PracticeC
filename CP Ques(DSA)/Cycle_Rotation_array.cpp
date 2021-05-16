#include <iostream>
using namespace std;
 
int main(){
    int n, i;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    	cin>>arr[i];
 
    cout<<"Given array is:";
    for(i=0; i<n; i++)
        cout<<arr[i]<<"\t";
 
	int x = arr[n-1];
    for(i=n-1; i>0; i--)
    arr[i] = arr[i - 1];
    arr[0] = x;
 
    cout<<"Rotated array is:";
    for(i=0; i<n; i++)
        cout<<arr[i]<<"\t";
 
    return 0;
}