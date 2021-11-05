#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
// Just insert the elements in a set and output the second element in the set
// if the the second elemnet exists, else output NO
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    if (s.size() == 1)
        cout << "NO";
    else
        cout << *(++s.begin());
}