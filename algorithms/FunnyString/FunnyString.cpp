#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



int main() {

    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        string str;
        cin >> str;
        
        // find reverse
        string rev = str;
        
        for(int j = 0; j < str.size(); j++)
        {
            rev[j] = str[str.size() - j - 1];
        }
        
        int j = 0;
        for(j = 1; j < str.size(); j++)
            if(abs(rev[j] - rev[j-1]) != abs(str[j] - str[j-1]))
            {
            
                cout << "Not Funny" << endl;
                break;
            }
        if(j == str.size())
            cout << "Funny" << endl;
        
    }
    return 0;
}