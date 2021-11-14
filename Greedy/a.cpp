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
    stack<char> s;
    for(int i = 0; i<n; i++)
    {
        char c; cin >> c;
        if(!s.empty() and s.top() != c)
        {
            s.pop();
        }
        else s.push(c);
    }
    cout << s.size();
}