#include <iostream>
using namespace std;
int Union(int arr1[], int arr2[], int a, int b){
    int i=0, j=0;
	while (i<a && j<b){
        if (arr1[i] < arr2[j])
            cout<<arr1[i++]<<"\t";
        else if (arr2[j] < arr1[i]){
            cout<<arr2[j++]<<"\t";
        }
        else{
            cout<<arr2[j++]<<"\t";
            i++;
        }
    }
	while (i<a)
        cout<<arr1[i++]<<"\t";
 
    while (j<b)
        cout<<arr2[j++]<<"\t ";
}
 
int Intersection(int arr1[], int arr2[], int a, int b){
	int i=0, j=0;
	while (i<a && j<b){
    	if (arr1[i] < arr2[j]) 
    		i++; 
    	else if (arr2[j] < arr1[i]) 
    		j++; 
    	else{ 
    		cout<<arr2[j]<<"\t"; 
    		i++; 
    		j++; 
    	} 
	} 
}
int main(){
    int a, b;
    cin>>a;
    cin>>b;
    int arr1[a];
    int arr2[b];
    for(int i=0; i<a; i++){
    	cin>>arr1[i];
    }
    for(int i=0; i<b; i++){
    	cin>>arr2[i];
    }
    Union(arr1, arr2, a, b);
    Intersection(arr1, arr2, a, b);
    return 0;
}