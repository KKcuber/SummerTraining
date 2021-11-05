#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

// Just a basic question based on map data structure
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<string, int> m;
    tc{
        int q; cin >> q;
        string x; cin >> x;
        if(q == 1)
        {
            int y; cin >> y;
            m[x] += y;
        }
        else if(q == 2)
        {
            m.erase(x);
        }
        else
        {
            if(m.count(x))
                cout << m[x] << endl;
            else
                cout << "0" << endl;
        }
    }
}