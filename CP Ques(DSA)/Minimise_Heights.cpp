#include <iostream>
 
using namespace std;
 
int main() {
	int n, k;
	cin>>k;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
 
	if(n == 1)
        cout<<0;
    //sort(arr, arr+n);
    int diff = arr[n-1]-arr[0];
    int minimum = arr[0]+k;
    int maximum = arr[n-1]-k;
    int temp = 0;
    if (minimum > maximum){
        temp = minimum;
        minimum = maximum;
        maximum = temp;
    }
    for (int i=1; i<n-1; i++){
        int difference = arr[i]-k;
        int sum = arr[i]+k;
        if (difference>=minimum || sum<=maximum)
            continue;
        if (maximum-difference <= sum-minimum)
            minimum = difference;
        else
            maximum = sum;
    }
    cout<<min(diff, maximum-minimum);
	return 0;
}