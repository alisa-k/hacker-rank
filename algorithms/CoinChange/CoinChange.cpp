#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long numWays(int N, int M, int C[]) {
    unsigned long long res[N+1] = {0};
    
    res[0] = 1; 
    
    for (int j = 0; j < M; j++) {
        for (int i = C[j]; i <= N; i++) {
            res[i] += res[i-C[j]];
        }
    }
    
    return res[N];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N = 0;
    int M = 0;
    cin >> N;
    cin >> M;
    
    int C[M];
    for (int i = 0; i < M; i++)
        cin >> C[i];
    
    cout << numWays(N, M, C);
    
    return 0;
}