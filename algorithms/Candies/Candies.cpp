#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void minCandies(int scores[], int n) {
    int candies[n] = {0};
    candies[0] = 1;
    candies[n-1] = 1;
    
    // end cases
    if (scores[0] > scores[1])
        candies[0] = -1;
    if (scores[n-1] > scores[n-2])
        candies[n-1] = -1;
    
    // place 1's where mins occur, -1's where maxs occur
    for (int i = 1; i < n-1; i++) {
        if (scores[i] <= scores[i-1] && scores[i] <= scores[i+1]) {
            if (candies[i] != -1)
                candies[i] = 1;
        }
        else if (scores[i] >= scores[i-1] && scores[i] >= scores[i+1]) {
            if (candies[i] != 1)
                candies[i] = -1; 
        }
    }
    
    // beginning case
    if (candies[0] == 1) {
        int k = 1;
        while (candies[k] != -1 && candies[k] != 1) {
            candies[k] = candies[k-1] + 1;
            k++;
        }
        if (candies[k] == -1) {
            candies[k] = candies[k-1] + 1;
        }
        else if (candies[k] > 1) {
            if (candies[k] <= candies[k-1] + 1)
                candies[k] = candies[k-1] + 1;
        }
    }
    
    // increment around mins until we come upon a max
    for (int i = 1; i < n-1; i++) {
        if (candies[i] == 1) {
            int j = i-1;
            int k = i+1;
            while (candies[j] == 0) {
                candies[j] = candies[j+1] + 1;
                j--;
            }
            if (candies[j] == -1) {
                candies[j] = candies[j+1] + 1;
            }
            else if (candies[j] > 1) {
                if (candies[j] <= candies[j+1] + 1)
                    candies[j] = candies[j+1] + 1;
            }
            while (candies[k] == 0) {
                candies[k] = candies[k-1] + 1;
                k++;
            }
            if (candies[k] == -1) {
                candies[k] = candies[k-1] + 1;
            }
            else if (candies[k] > 1) {
                if (candies[k] <= candies[k-1] + 1)
                    candies[k] = candies[k-1] + 1;
            }
        }
    }
    
    // end case
    if (candies[n-1] == 1) {
        int j = n-2;
        while (candies[j] == 0) {
            candies[j] = candies[j+1] + 1;
            j--;
        }
        if (candies[j] == -1) {
            candies[j] = candies[j+1] + 1;
        }
        else if (candies[j] > 1) {
            if (candies[j] <= candies[j+1] + 1)
                candies[j] = candies[j+1] + 1;
        }
    }
    

    int total = 0;
    for (int i = 0; i < n; i++) {
        //cout << candies[i] << " ";
        total += candies[i];
    }
    //cout << endl;
    cout << total << endl;
}

int main() {
    int n;
    cin >> n;
    int scores[n];
    for (int i = 0; i < n; i++)
        cin >> scores[i];
    
    minCandies(scores, n);
    return 0;
}