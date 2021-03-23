//Even Odd checker
#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
string odd_even(int i);
int main() {
   int number;
   cout << "Enter an integer : ";
   cin>>number;
   cout << "Result : " << odd_even(number);
   getch();
   return (0);
}
string odd_even(int number) {
   if (number % 2 == 0) {
      return "YOUR NUMBER IS EVEN NUMBER";
   } else {
      return "YOUR NUMBER IS ODD NUMBER";
   }
}
