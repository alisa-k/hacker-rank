#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>

using namespace std;

int main() {
    int N; 
    cin >> N;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        double x;
        cin >> x;
        sum += x;
    }
    cout << fixed;
    cout << setprecision(1);
    cout << 0.5 * sum;
    return 0;
}
