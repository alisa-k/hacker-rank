#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long stockMaximize(vector<long long>& prices, int N) {
    long long profit = 0;
    long long stocks = 0;
    vector<long long> prices_idx;
    for (int i = 0; i < N; i++)
        prices_idx.push_back(i);
    
    // compare function
    auto comp = [&prices](size_t i, size_t j) {
        if (prices[i] == prices[j])
            return true;
        return prices[i] < prices[j];
    
    };
        
    // sort prices_idx
    sort(prices_idx.begin(), prices_idx.end(), comp);
    
    int last = N-1;
    for (int i = 0; i < N; i++) {
        // skip over elements we've already passed
        while (last > 0 && i > prices_idx[last]) {
            last--;
        }
        if (prices[i] < prices[prices_idx[last]]) {
            // buy
            stocks++;
            profit-=prices[i];
        }
        else {
            // sell or do nothing
            profit+=stocks * prices[i];
            stocks = 0;
        }
    }
    return profit;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<long long> prices;
        for (int j = 0; j < N; j++) {
            long long x;
            cin >> x;
            prices.push_back(x);
        }         
        
        cout << stockMaximize(prices, N) << endl;
    }
        
    return 0;
}