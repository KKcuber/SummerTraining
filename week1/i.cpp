#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

/* So the logic that we are goin to use here is to maintain a deque consisting of 
only the indices of possible maximum elements in the subarray in sorted order. */
// The solution is O(nt) time and O(kt) space.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    tc{
        int n, k; cin >> n >> k;
        int a[n];
        deque<int> dq;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i]; 
        }
        for(int i = 0; i < k; i++)
        {
            while(!dq.empty() and a[i] >= a[dq.back()]) // popping from the back until the backmost element is greater than the element we are going to insert
            {
                dq.pop_back();
            }
            dq.push_back(i); // we will push the indices of the elements in the array as we are not storing all the k elements in the deque
        }
        cout << a[dq.front()] << " ";
        for(int i = k; i < n; i++)
        {
            while(!dq.empty() and a[i] >= a[dq.back()]) // popping from the back until the backmost element is greater than the element we are going to insert
            {
                dq.pop_back();
            }
            dq.push_back(i);
            //checking whether the frontmost element is in the k size subarray or not
            while(!dq.empty() and dq.front() <= i-k)
            {
                dq.pop_front();
            }
            cout << a[dq.front()] << " ";
        }
        cout << "\n";
    }
}