#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isZero(int el) {
    return (el == 0);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    
    sort(arr.begin(), arr.end(), [](int i, int j) { return (i > j);});
    
    vector<int>::iterator it = arr.begin();
    while (!arr.empty()) {
        int size = arr.size();
        cout << size << endl;
        // decrease each by value smallest element
        for (auto& el: arr) {
            el-=arr[size-1];
        }
        // remove 0s
        arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
    }
    return 0;
}
