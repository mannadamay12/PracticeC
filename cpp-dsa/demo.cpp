#include<iostream>

using namespace std;

int main(){
    int x;
    cin >> x;
    int *y = &x;
    cout << y;
}