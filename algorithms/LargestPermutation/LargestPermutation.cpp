#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    int K;
    cin >> N >> K;
    
    if (K > N-1)
        K = N-1;
    
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    for (int i = 0; i < N && K > 0; i++) {

        int max = arr[i];
        int max_ind = i;
        for (int j = i+1; j < N; j++) {
            if (arr[j] > max) {
                max = arr[j];
                max_ind = j;
            }
        }
        
        if (max != arr[i]) {
            K--;
            swap(arr[i], arr[max_ind]);
        }
    }
    
    
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    
    return 0;
}