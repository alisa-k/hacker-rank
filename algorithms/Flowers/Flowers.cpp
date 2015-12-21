#include<iostream>
#include<cstdlib>
using namespace std;

int compare (const void * a, const void * b) {
  return ( *(int*)b - *(int*)a );
}

int main(void) { 

    int N, K;
    cin >> N >> K;
    int C[N];
    for(int i = 0; i < N; i++){
        cin >> C[i];
    }
    
    // sort C in descending order
    qsort (C, N, sizeof(int), compare);
   
    int M = N/K;
    int R = N%K;
    int P = M * K;

    int result = 0;
    int X = 0;
    
    for (int i = 0; i < P; i++) {
        if (i % K == 0)
            X++;
        result += C[i] * X; 
    }
    
    X++;
    for (int i = P; i < N; i++) {
        result += C[i] * X;
    }
    
    cout << result << "\n";
   
    return 0;
}