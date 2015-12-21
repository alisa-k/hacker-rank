#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long findOptimal(long long *arr, int N) {
    int moves[N] = {0};
    long long sums[N] = {0};
    moves[N-1] = 1;
    moves[N-2] = 2;
    moves[N-3] = 3;
    sums[N-1] = arr[N-1];
    sums[N-2] = arr[N-2] + sums[N-1];
    sums[N-3] = arr[N-3] + sums[N-2];
    
    for (int i = N-4; i >= 0; i--) {
        // case 1 //
        sums[i] = arr[i];
        i+moves[i+1]+1 < N ? sums[i]+= sums[i+moves[i+1]+1] : sums[i] += 0;
        moves[i] = 1;
        
        long long s2 = arr[i] + arr[i+1];
        i+moves[i+2]+2 < N ? s2+= sums[i+moves[i+2]+2] : s2 += 0;
       
        long long s3 = arr[i] + arr[i+1] + arr[i+2];
        i+moves[i+3]+3 < N ? s3+= sums[i+moves[i+3]+3] : s3 += 0;
        
        // case 2
        if ( s2 > sums[i]) {
            sums[i] = s2;
            moves[i] = 2;
        }
        // case 3
        if ( s3 > sums[i]) {
            sums[i] = s3;
            moves[i] = 3;
        }
    }
    
    return sums[0];
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        long long arr[N];
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }
        cout << findOptimal(arr, N) << endl;
    }
    return 0;
}