#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        int K;
        cin >> N;
        cin >> K;
        vector<int> vec1;
        vector<int> vec2;
        
        int x;
        for (int j = 0; j < N; j++) {
            cin >> x;
            vec1.push_back(x);
        }
        for (int j = 0; j < N; j++) {
            cin >> x;
            vec2.push_back(x);
        }
        
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end(), [](int a, int b) {
            return a > b; 
        });
        
        vector<int>::iterator it1 = vec1.begin();
        vector<int>::iterator it2 = vec2.begin();
        while (it1 != vec1.end() && *it1 + *it2 >= K) {
            ++it1;
            ++it2;
        }
        if (it1 == vec1.end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;    
    }
    
    return 0;
}