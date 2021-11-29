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
    long long n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) % 2 == 0) {
        cout << abs(a - b) / 2 << endl;
        return 0;
    }
    if (a > b) {
        swap(a, b);
    }
    long long x = (b - a - 1) / 2 + a;
    long long y = (b - a - 1) / 2 + n - b + 1;
    cout << min(x, y) << endl;
}