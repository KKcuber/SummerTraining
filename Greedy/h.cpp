#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

char diffchar(char c1, char c2)
{
    if(c1 != 'a' && c2 != 'a')
    {
        return 'a';
    }
    else if(c1 != 'b' and c2 != 'b')
    {
        return 'b';
    }
    else return 'c';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin >> n >> t;
    string s1, s2, s = "";
    cin >> s1 >> s2;
    int samecount = 0;
    t = n-t;
    for(int i = 0; i < n; i++)
    {
        if(s1[i] ==  s2[i])
        {
            samecount++;
        }
    }
    if(2*(t-samecount)+samecount > n)
    {
        cout << -1;
        return 0;
    }
    if(samecount < t)
    {
        int cur = 1;
        for(int i =0, tot = 0; i <n; i++)
        {
            if(s1[i] ==  s2[i])
            {
                s.push_back(s1[i]);
            }
            else if(tot < t - samecount)
            {
                if(cur == 1)
                {
                    s.push_back(s1[i]);
                    cur = 2;
                }
                else
                {
                    s.push_back(s2[i]);
                    cur = 1;
                    tot++;
                }
            }
            else
            {
                s.push_back(diffchar(s1[i], s2[i]));
            }
        }
    }
    else
    {
        for(int i =0, same = 0; i <n; i++)
        {
            if(s1[i] ==  s2[i] and same < t)
            {
                s.push_back(s1[i]);
                same++;
            }
            else
            {
                s.push_back(diffchar(s1[i], s2[i]));
            }
        }
    }
    cout << s;
}