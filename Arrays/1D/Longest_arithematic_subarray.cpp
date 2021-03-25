//longest arithematic subarray
//Google Kickstart
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int ans=2, curr=2, pd=a[1]-a[0], j=2;
	while(j<n){
		if(pd == a[j]-a[j-1]){
			curr++;
		}
		else{
			pd = a[j]-a[j-1];
			curr=2;
		}
		ans = max(ans,curr);
		j++;
	}
	cout<<ans<<endl; 
	return 0;
}
