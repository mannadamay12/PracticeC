#include <iostream>
#include<climits>
using namespace std;
int minJumps(int arr[], int n){
	if(n==1)
		return 0;
	int r = INT_MAX;
	for(int i=n-2; i>=0; i--){
		if(i+arr[i] >= n-1){
			int sr = minJumps(arr, i+1);
			if(sr != INT_MAX)
				r = min(r, sr+1);
		}
	}
	return r; 
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<minJumps(arr, n);
	return 0;
}