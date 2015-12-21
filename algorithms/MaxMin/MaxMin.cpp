#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int compare (const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];
    
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    
    qsort(list, N, sizeof(int), compare);
    
    int first = 0;
    int last = K-1; 
    
    while(last < N) {
        if (unfairness > (list[last] - list[first]))
            unfairness = list[last] - list[first];
        first++;
        last++;
    } 
    
    cout << unfairness << "\n";
    return 0;
}
