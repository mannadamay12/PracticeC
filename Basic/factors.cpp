//Factors of Number
#include<iostream>
using namespace std;
int main() {
   int num;
   cin>>num;
   cout << "The factors of " << num << " are : ";
   for(int i=1; i <= num; i++) {
      if (num % i == 0)
      cout << i << " ";
   }
   return 0;
}
