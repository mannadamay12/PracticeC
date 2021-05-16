#include <iostream>
#include<string>
using namespace std;
 
int main()
{
    string str= "sample program";
    int freq[26] = { 0 };
    int max = -1;
    char result;
    int len = str.size();
    for (int i = 0; i < len; i++)
        freq[str[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        if (max < freq[i]) {
            max = freq[i];
            result = (i + 'a');
        }
    cout << "Maximum occurring character = " << result << endl;
    return 0;
}