int main() 
{
    long long n, k; cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        prices.push_back(p);
    }
    
    int answer = 0;
    
    sort(prices.begin(), prices.end());
    
    vector<int>::iterator it = prices.begin();
    
    while (it != prices.end() && k > 0) {
        k = k - *it;
        ++it;
        if (k >= 0)
            answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}