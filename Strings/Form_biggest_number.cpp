#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    string s = "5611516115151";

    sort(s.begin(), s.end(), greater<int>());

    cout<<s<<endl;

    return 0;
}