#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    ll t;    \
    cin >> t; \
    while (t--)

ll minimumValue(ll val, vector<ll> &bsum)
{
    auto it = lower_bound(bsum.begin(), bsum.end(), val);
    if(it != bsum.end())
    {
        if(it != bsum.begin())
        {
            ll next = *it;
            ll prev = *(--it);
            return (next - val) < (val - prev) ? next - val : val - prev;
        }
        else return *it - val;
    }
    else return val - *(--it);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,q; cin >> n >> m >> q;
    vector<ll> a(n), b(m);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];

    // precalculating all posibble values of the b part
    ll asum = 0;vector<ll> bsum(m - n + 1, 0);
    for(ll i = 0; i < n; i++)
    {
        if(i%2 == 0) asum += a[i];
        else asum -= a[i];
    } 
    for(ll i = 0; i <= m-n; i++)
    {
        if(i == 0)
        {
            for(ll j = i; j < n+i; j++)
            {
                if((j-i)%2 == 0) bsum[i] += b[j];
                else bsum[i] -= b[j];
            }
        }
        else{
            if(n%2 == 1) bsum[i] = -bsum[i-1] + b[i-1] + b[i+n-1];
            else bsum[i] = -bsum[i-1] + b[i-1] - b[i+n-1];
        }
    } 
    sort(bsum.begin(), bsum.end());

    cout << minimumValue(asum, bsum) << endl;
    // processing the queries
    for(ll i = 0; i < q; i++)
    {
        int l,r, x; cin >> l >> r >> x;
        if((r-l)%2 == 0)
        {
            if(l%2 == 1) asum += x;
            else asum -= x;
        }
        cout << minimumValue(asum, bsum) << endl;
    }
}