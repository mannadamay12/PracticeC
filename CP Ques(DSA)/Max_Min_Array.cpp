#include <iostream>
using namespace std;
 
int main() {
	int n, min=0, max=0;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i]; 
	}
	if(n==1){
		min=max=arr[0];
	}
	if(arr[0]>arr[1]){
		max=arr[0];
		min=arr[1];
	}
	else{
		max=arr[1];
		min=arr[0];
	}
	for(int i=2; i<n; i++){
		if(arr[i]>max)
			max=arr[i];
		else if(arr[i]<min)
			min=arr[i];
	}
	cout<<"Minimum element: "<<min<<endl;
	cout<<"Maximun element: "<<max<<endl;
	return 0;
}