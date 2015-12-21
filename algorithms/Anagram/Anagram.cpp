#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int num_chars(string s) {
    int alphabet[26];
    for (int i = 0; i < 26; i++)
        alphabet[i] = 0;
    int len = s.size()/2;
    
    string s1 = s.substr(0, len);
    string s2 = s.substr(len, len);
    
    for (int i = 0; i < len; i++)
        alphabet[s2[i]-'a'] += 1;
    
    for (int i = 0; i < len; i++)
        alphabet[s1[i]-'a']--;
    
    int total = 0;
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > 0)
            total += alphabet[i];
    }
    
    return total;
}
int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        
        if (s.size()%2 != 0)
            cout << -1 << endl;
        else
            cout << num_chars(s) << endl;
            
    }
    
    return 0;
}