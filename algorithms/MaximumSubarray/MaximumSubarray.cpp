#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max3(int x, int y, int z){
    
    int max = x;
    
    if (y > max)
        max = y;
    if (z > max)
        max = z;
    
    return max;
}

int nonContMaxSubSum(int len, int *arr){
    
    int max = arr[0];
    
    for (int i = 1; i < len; i++){
        max = max3(max, arr[i], max+arr[i]);
    }
    
    return max;
}

int contMaxSubSum(int len, int *arr){
    
    int max = arr[0];
    int new_sum = arr[0];
    
    for (int i = 1; i < len; i++){
        if (arr[i] > (new_sum + arr[i]))
            new_sum = arr[i];
        else
            new_sum = new_sum + arr[i];
        
        if (new_sum > max)
            max = new_sum;
    }
    return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test_cases = 0;
    cin >> test_cases;
    
    int size = 0;
    for (int i = 0; i < test_cases; i++){
        cin >> size;
        int *arr = new int[size];
        for (int j = 0; j < size; j++){
            cin >> arr[j];
        }
        cout << contMaxSubSum(size, arr) << " ";
        cout << nonContMaxSubSum(size, arr);
        delete [] arr;
        cout << endl;
    }
    
    return 0;
}