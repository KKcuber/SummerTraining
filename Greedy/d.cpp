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
    int n,k; cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    set<tuple<ll, int, int>> s;
    ll sum = 0;
    for(int i = 0; i<n; i++) sum += a[i];
    cout << sum << " ";
    s.insert({sum-a[0],0,n-2});
    s.insert({sum-a[n-1], 1, n-1});
    for(int i = 1; i<k; i++)
    {
        s.
    }
}