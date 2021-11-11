#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

/* We use a greedy strategy here.
 We always pick the highest number in the set at that moment
 as the one of the numbers constituting the sum required
 which is the maximum of the elements removed in the previous iteration.*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    tc{
        int n; cin >> n;
        multiset<int> s;
        for(int i = 0; i<2*n; i++)
        {
            int x; cin >> x;
            s.insert(x);
        }
        int yesflag = 0; int sum;
        // this queue stores the pairs which are removed in order
        queue<int> q;
        // here i iterates over the possible second value along with the highest element
        for(int i = 0; i < 2*n-1; i++)
        {
            // making a copy of the set to preserve the original set
            multiset<int> c = s;
            auto it = c.begin();
            for(int j = 0; j<i; j++) it = ++it;
            // here j iterates over all the removals
            for(int j = 0; j<n; j++)
            {
                auto endit = --c.end();
                sum = *endit;
                q.push(*endit); q.push(*it);
                c.erase(it); c.erase(endit);
                if(j != n-1)
                {
                    it = c.find(sum - *(--c.end()));
                    // if a number which fits into the sum along with the highest number does not exist then we break and go on to next pair of starting numbers
                    if(it == c.end() || it == (--c.end()))
                    {
                        while(q.size()) q.pop(); // emptying the queue
                        break;
                    }
                }
            }
            if(c.size() == 0)
            {
                yesflag = 1;
                cout << "YES" << endl;
                int max = q.front();
                q.pop();
                int next = q.front();
                q.pop();
                cout << max + next << endl;
                cout << max << " " << next << endl;
                for(int k = 1; k < n; k++)
                {
                    max = q.front();
                    q.pop();
                    next = q.front();
                    q.pop();
                    cout << max << " " << next << endl;
                }
                break;
            }
        }
        if(!yesflag)
            cout << "NO" << endl;
    }
    return 0;
}