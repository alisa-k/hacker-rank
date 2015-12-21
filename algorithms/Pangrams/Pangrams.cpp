#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    
    bool arr[26];
    for (int i = 0; i < 26; i++)
        arr[i] = {false};
    
    string str;
    string mystr;
    while (cin >> str) {
        mystr += str + " ";
    }
    
    transform(mystr.begin(), mystr.end(), mystr.begin(), ::tolower);
    
    for (int i = 0; i < mystr.size(); i++) {
        arr[mystr[i] - 'a'] = true;
    }
    
    for (int i = 0; i < 26; i++) {
        if (arr[i] == false) {
            cout << "not pangram";
            return 0;
        }
    }
    
    cout << "pangram";
    
    return 0;
}