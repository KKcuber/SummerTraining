#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
// Just store string-year pairs in a vector and sort it and use lowerbound to query
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<string, int>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int q; cin >> q;
    for(int i=0; i<q; i++)
    {
        string country;
        int num;
        cin >> country >> num;
        cout << (lower_bound(v.begin(), v.end(), make_pair(country, 0)) + num - 1)->second << endl;
    }
}