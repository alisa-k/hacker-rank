#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int *ends, int left, int right, int key) {
    int mid = (left + right)/2;
    
    if (key > ends[mid]) {
        left = mid + 1;
    }
    else if (key <= ends[mid]) {
        if (key > ends[mid-1])
            return mid;
        right = mid - 1;
    }
    
    return binarySearch(ends, left, right, key);
}

// O(nlgn) time
int LIS1(int N, int arr[]) {
    int ends[N] = {0};
    ends[0] = arr[0];
    
    int last = 0;
    for (int i = 1; i < N; i++) {
        // create new "list"
        if (arr[i] > ends[last]) {
            ends[++last] = arr[i];
        }
        else {
            // do binary search on ends & replace first larger
            ends[binarySearch(ends, 0, last, arr[i])] = arr[i];
        }
    }
    
    return last+1; 
}

// O(n^2) time
int LIS2(int N, int arr[]) {
    int L[N] = {0};
    L[0] = 1; 
    
    int maxLength = 1;
    for (int j = 1; j < N; j++) {
        L[j] = 1;
        for (int i = 0; i < j; i++) {
            if (arr[j] > arr[i] && L[i] > L[j]) {
                L[j] = L[i] + 1;
            }
        }
        if (L[j] > maxLength) 
            maxLength = L[j];
    }
    
    return maxLength;
}

// O(2^n) time
int LIS3(int N, int arr[], int i) {
    
    if (i == 0)
        return 1;
    
    int maxLength = 1;
    for (int j = 0; j < i; j++) {
        int max = 1;
        if (arr[j] < arr[i]) {
            max = 1 + LIS3(N, arr, j);
            if (max > maxLength)
                maxLength = max;
        }
    }
    
    return maxLength;
}

int main() {

    int size = 0;
    cin >> size;
    
    int arr[size] = {0};
    
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    cout << LIS1(size, arr) << endl;
        
    return 0;
}