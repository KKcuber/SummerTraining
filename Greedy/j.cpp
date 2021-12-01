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
    multiset<long long> buy, sold; 
	long long money = 0;
    int n;  cin >> n; 
	for(int i = 0; i < n; ++i) {
		long long x; cin >> x;
		int b = -1;
		if(!buy.empty() && *buy.begin() < x) {
			b = x - *buy.begin();
		}
		int s = -1;
		if(!sold.empty() && *sold.begin() < x) {
			s = x - *sold.begin();
		}
		if(s == -1 && b == -1) {
			buy.insert(x);
		} else if(s > b) {
			money += s;
			buy.insert(*sold.begin());
			sold.erase(sold.begin());
			sold.insert(x);
		} else {
			money += b;
			buy.erase(buy.begin());
			sold.insert(x);
		}
	}
	cout << money << endl;
}