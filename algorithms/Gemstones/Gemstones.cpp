#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;


int main() {
    int numRocks;
    cin >> numRocks;
    
    string rocks[numRocks];
    
    int arr[26];
    for (int i = 0; i < 26; i++)
        arr[i] = 0;
    for (int i = 0; i < numRocks; i++) {
        cin >> rocks[i];
        for (int j = 0; j < rocks[i].size(); j++)
            if (arr[rocks[i][j] - 'a'] == i)
                arr[rocks[i][j] - 'a'] += 1;
    }
    
    
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[i] == numRocks)
            count++;
    }
    
    cout << count;
    
    return 0;
}
