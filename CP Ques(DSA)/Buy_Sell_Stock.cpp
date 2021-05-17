#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
   int maxProfit(vector<int>& p) {
      int endWithSell = 0;
      int endWithBuy = INT_MIN;
      int prevBuy =0, prevSell = 0;
      
      for(int i =0;i<p.size();i++){
         prevBuy = endWithBuy;
         endWithBuy = max(endWithBuy,prevSell - p[i]);
         prevSell = endWithSell;
         endWithSell = max(endWithSell, prevBuy + p[i]);
      }
      
      return endWithSell;
   }
};
int main(){
   Solution ob;
   vector<int> v = {1,2,3,0,2};
   cout << (ob.maxProfit(v));
   return 0;
}
