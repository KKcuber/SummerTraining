#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m,t,r; cin>>m>>t>>r;
    if(t<r)
    {
        cout << -1;
        return 0;
    }
    int a[m];
    for(int i = 0; i<m; i++)
    {
        cin >> a[i];
    }
    int ans = r;
    vector<int> candles;
    for(int i = a[0]-r; i<a[0]; i++) candles.push_back(i);
    for(int i = 1; i<m; i++)
    {
        int req = r - (candles.end() - lower_bound(candles.begin(), candles.end(), a[i] - t));
        if(req<0) req = 0;
        for(int j = a[i] - req; j < a[i]; j++) candles.push_back(j);
    }
    cout << candles.size();
}