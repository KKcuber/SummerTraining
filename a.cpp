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
    int n; cin >> n;
    set<int> s;
    for(int i = 0; i<n; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
    if(s.size()>1)
        cout << *next(s.begin());
    else
        cout << "NO";
}