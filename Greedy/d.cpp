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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    map<long long, vector<pair<int, int>>> mp;
    mp[accumulate(v.begin(), v.end(), 0LL)] = {{0, n - 1}};
    set<pair<int, int>> inserted;
    while (k--) {
        auto it = mp.rbegin();
        long long val = it->first;
        cout << val << ' ';
        int l = it->second.back().first;
        int r = it->second.back().second;
        it->second.pop_back();
        if (it->second.empty()) mp.erase(val);
        if (!inserted.count({l + 1, r})) mp[val - v[l]].emplace_back(l + 1, r), inserted.insert({l + 1, r});
        if (!inserted.count({l, r - 1})) mp[val - v[r]].emplace_back(l, r - 1), inserted.insert({l, r - 1});
    }
}