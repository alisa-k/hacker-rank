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
        int A;
        cin >> A;
        int B;
        cin >> B;
        
        cout << floor(sqrt(B)) - ceil(sqrt(A)) + 1 << endl;
    }
    return 0;
}