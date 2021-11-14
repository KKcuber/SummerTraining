#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

unordered_map<ll, ll> m;
// Number of x's = number of distinct (b_i - p_i)'s
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k,n; cin >> k >> n;
    ll a[k], b[n];// using long long instead of int because prefix sums might go beyond 2 billion
    set<ll> s; 
    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
        if(i != 0)
            a[i] +=  a[i-1]; // finding prefix sums
        s.insert(a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(auto &x : s)
        {
            m[b[i] - x]++;
        }
    }
    int ans = 0;
    for(auto &x : m)
    {
        if(x.second == n) ans++;
    }
    cout << ans;
}