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

void findPattern(vector<string>& G, vector<string>& P, int R, int r) {
    vector<string>::iterator g_it = G.begin();
    vector<string>::iterator p_it = P.begin();
    vector<string>::iterator last = g_it + R - r + 1;
    
    while (g_it != last) {
        size_t found = (*g_it).find((*p_it)); 
        
        // if no match found, go to next row of G
        if (found == -1) {
            ++g_it;
            continue;
        }

        while (found != -1) {
            /* for current position, see if rows
            below also contain line of pattern */
            for (int i = 1; i < r; i++) {
                size_t curFound = (*(g_it+i)).find((*(p_it+i)), found);
                if (curFound == -1 || curFound != found)
                    break;
                // means that it found the complete pattern
                if (i == r-1) {
                    cout << "YES" << endl;
                    return;
                }
            }
            // find next occurence of substring in current row
            found = (*g_it).find((*p_it), found+1);
        }  
        ++g_it;    
    }
    cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        
        findPattern(G, P, R, r);
    }
    return 0;
}