#include<iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Matrix is:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    int x;
    cin>>x;

    bool flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==x){
                cout<<i+1<<" "<<j+1<<"\n";
            }
        }
    }
    if(flag){
        cout<<"Element Found\n";
    }
    else{
        cout<<"Element not Found\n";
    }
    return 0;
}