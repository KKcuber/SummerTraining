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
    ll N, L; cin >> N >> L;
    vector<ll> A(N);
    ll l = -1;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        if (i > 0 && A[i] + A[i - 1] >= L) l = i - 1;
    }
    if (l == -1) cout << "Impossible" << '\n';
    else {
        cout << "Possible" << '\n';
        for (ll i = 0; i < l; i++) {
        cout << (i + 1) << '\n';
        }
        for (ll i = N - 2; i > l; i--) {
        cout << (i + 1) << '\n';
        }
        cout << (l + 1) << '\n';
    }
    return 0;
}