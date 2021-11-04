#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    ll t;    \
    cin >> t; \
    while (t--)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll v,h,n;
    cin >> v >> h >> n;
    string st;
    ll cut;
    multiset<ll> hpos, hlen, vlen, vpos;
    hpos.insert(h), hpos.insert(0),vpos.insert(v), vpos.insert(0);
    hlen.insert(h), vlen.insert(v);
    for (ll i=0; i<n; i++)
    {
        cin >> st >> cut;
        if(st == "H")
        {
            hpos.insert(cut);
            auto it = hpos.find(cut);
            hlen.erase(hlen.find(*next(it) - *prev(it)));
            hlen.insert(*next(it) - cut);
            hlen.insert(cut - *prev(it));
        }
        else
        {
            vpos.insert(cut);
            auto it = vpos.find(cut);
            vlen.erase(vlen.find(*next(it) - *prev(it)));
            vlen.insert(*next(it) - cut);
            vlen.insert(cut - *prev(it));
        }
        cout << (*hlen.rbegin()) * (*vlen.rbegin()) << endl;
    }
}