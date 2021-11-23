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
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = INT_MAX;
    for (int i = 0; i < 2 * n - 1; i += 2)
    {
        for (int j = i + 1; j < 2 * n; j += 2)
        {
            int sum = 0;
            for (int a = 0; a < i - 1; a += 2)
                sum += (v[a + 1] - v[a]);
            for (int b = i + 1; b < j - 1; b += 2)
                sum += (v[b + 1] - v[b]);
            for (int c = j + 1; c < 2 * n - 1; c += 2)
                sum += (v[c + 1] - v[c]);
            ans = min(ans, sum);
        }
    }
    cout << ans;
}
