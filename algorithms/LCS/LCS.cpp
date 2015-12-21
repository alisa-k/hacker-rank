#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void LCS(int *x, int *y, int m, int n) {
    // create & initialize c[i,j] table
    int c[m+1][n+1];
    for (int i = 0; i < m+1; i++)
        c[i][0] = 0;
    for (int j = 0; j < n+1; j++)
        c[0][j] = 0;
    
    // find max length
    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (x[i-1] == y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else if (c[i-1][j] >= c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
        }
    }
    
    // reconstruct LCS
    int len = c[m][n];
    int lcs[len];
    int i = m;
    int j = n;
    while (i != 0 && j != 0) {
        int currMax = max(c[i-1][j], c[i][j-1]);
        if (c[i][j] != currMax) {
            //place current
            lcs[--len] = x[i-1];
            i--;
            j--;
        }
        else if (c[i-1][j] >= c[i][j-1])
            i--;
        else
            j--;
    }
    
    for (int i = 0; i < c[m][n]; i++)
        cout << lcs[i] << " ";
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int y[n];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    int x[m];
    for (int i = 0; i < m; i++)
        cin >> x[i];
    
    LCS(x, y, m, n);
    
    return 0;
}