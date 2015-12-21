#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nearestSum(int arr[], int n, int k) {
    int sums[k+1] = {0};
    sums[0] = 1;
    
    // for each number in arr
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j < k+1; j++) {
            sums[j] += sums[j-arr[i]]; 
        }
        if (sums[k] != 0)
            return k;
    }
    
    int max = 0;
    for (int i = k; i > 0; i--) {
        if (sums[i] > 0) {
            max = i;
            break;
        }
    }
    
    return max;
}

int main() {
    int T; 
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        int k;
        cin >> n >> k;
        int arr[n];
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        cout << nearestSum(arr, n, k) << endl;
    }

    
    return 0;
}