#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)


// This question is just brute force implementation of the problem. We can see that O(n^2) is good enough, so we go with brute force.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    int a[n];
    int minimum = n+1;
    int minIndex = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        int start = a[i] - i*k;
        // because the tree heights cant be negative so we just skip the case where start becomes negative
        if(start <= 0)
            continue;
        int mins = 0;
        for(int j = 0; j < n; j++)
        {
            if(a[j] != start + j*k)
                mins++;
        }
        if(mins < minimum)
        {
            minimum = mins;
            minIndex = i;
        }
    }
    cout << minimum << endl;
    int start = a[minIndex] - minIndex*k;
    for(int j = 0; j < n; j++)
    {
        if(a[j] < start + j*k)
        {
            cout << "+ " << j+1 << " " << start + j*k - a[j] << endl;
        }
        if(a[j] > start + j*k)
        {
            cout << "- " << j+1 << " " << -start - j*k + a[j] << endl;
        }
    }
}
