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
    int k,n; cin >> k >> n;
    int a[n], diff[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    diff[0] = (k-a[n-1]) + a[0];
    for(int i=1; i<n; i++)
    {
        diff[i] = a[i] - a[i-1];
    }
    sort(diff, diff+n);
    cout << k-diff[n-1];
}