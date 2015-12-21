#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sortCustomers(int *arr, int n) {
    int customer[n];
    for (int i = 0; i < n; i++) {
        customer[i] = i;
    }
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j-1] > key)
        {
            arr[j] = arr[j-1];
            customer[j] = customer[j-1];
            j--;
        }
        arr[j] = key;
        customer[j] = i;
    }
    
    for (int i = 0; i < n; i++) {
        cout << customer[i] + 1 << " ";
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        arr[i] = x+y;
    }
    
    sortCustomers(arr, n);
    
    return 0;
}