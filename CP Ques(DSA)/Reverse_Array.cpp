#include <iostream>
using namespace std;
 
int main() {
	int n, s, e, i;
	cin>>n;
	int arr[n];
	for(i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Original Array:";
	for(i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	s=0;
	e=n-1;
	while(s<e){
		int temp=arr[s];
		arr[s]=arr[e];
		arr[e]=temp;
		s++;
		e--;
	}
	cout<<"Reversed array:";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}