#include <iostream>
using namespace std;
int findDuplicate(int nums[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (nums[i] == nums[j])
                return nums[i];
        }
    }
    return -1;
}
 
int main() {
    int n;
    cin>>n;
    int nums[n];
    for(int i=0; i<n; i++)
    	cin>>nums[i];
 
    cout<<findDuplicate(nums, n);
 
    return 0;
}