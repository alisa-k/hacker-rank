#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector <int>  ar) {

	if (ar.empty())
		return;
	
	vector<int>::iterator it = ar.end();
	--it;

	int x = *it;

	while (*(it-1) > x && it != ar.begin())
	{
        if (*(it-1) > x)
            *it = *(it-1);
        else
            *it = x;
        for (auto &el: ar)
        {
            cout << el << " ";    
        }
        cout << endl;
		it--;
	}
    *it = x;
    for (auto &el: ar)
    {
        cout << el << " ";    
    }
}

int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

insertionSort(_ar);
   
   return 0;
}