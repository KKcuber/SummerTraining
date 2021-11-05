#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

// Just a basic question based on the set data structure
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<int> s;
    tc{
        int y,x; cin >> y >> x;
        if(y == 1)
        {
            s.insert(x);
        }
        else if(y == 2)
        {
            if(s.count(x))
                s.erase(x);
        }
        else{
            if(s.count(x))
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}