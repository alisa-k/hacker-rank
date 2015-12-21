#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string s1;
    string s2;
    cin >> s1;
    cin >> s2; 
    
    int arr[26] = {0};
    
    for (int i = 0; i < s1.size(); i++) {
        arr[s1[i]-'a'] += 1;
    }
    
    for (int i = 0; i < s2.size(); i++) {
        arr[s2[i]-'a'] -= 1;
    }
    
    int total = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[i] != 0)
            total+=abs(arr[i]);
    }
    
    cout << total << endl;
    
    return 0;
}