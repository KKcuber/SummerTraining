#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
// We just need to find the maximum distance between a city and the nearest cellular tower to it
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int r = 0;
    for(int i = 0; i < n; i++)
    {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        int temp;
        if(it == b.begin())
            temp = *it - a[i];  
        else if(it == b.end())
        {
            temp = a[i] - *(it-1);
        }
        else
        {
            temp = min(*it - a[i], a[i] - *(it-1));
        }
        if(temp > r)
            r = temp;
    }
    cout << r;
}