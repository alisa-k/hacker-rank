#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0;grid_i < n;grid_i++){
       cin >> grid[grid_i];
    }
    
    vector<string>::iterator it = grid.begin();
    if (n > 1)
        ++it;
    
    while ((it+1) != grid.end()) {
        for (int i = 1; i < n-1; i++) {
            // potential cavity
            char cell = (*it)[i];
            
            // check left & right
            if ((*it)[i-1] >= cell || (*it)[i+1] >= cell)
                continue;
            // check above & below
            if ((*(it-1))[i] >= cell || (*(it+1))[i] >= cell)
                continue;
            
            // place X where cavity is
            (*it)[i] = 'X';
        }
        ++it;
    }
    
    // output modified strings
    it = grid.begin();
    while (it != grid.end()) {
        cout << *it << endl;
        ++it;
    }
    
    return 0;
}