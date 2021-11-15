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
    int n; cin >> n; int count[5] = {0};
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        count[x]++;
    }
    if(count[2]%2)
    {
        if(count[1])
        {
            count[1]--;
            count[3]++;
        }
        else count[3]++;
    }
    int more, less;
    if(count[1] > count[3])
    {
        more = ceil((count[1] - count[3])/4.0);
        less = count[3];
    }
    else
    {
        more = count[3];
        less = 0;
    }
    int ans = count[4] + count[2]/2 + more + less;
    cout << ans;
}