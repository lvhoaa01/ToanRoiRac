#include <bits/stdc++.h>
using namespace std;

int n;
typedef long long ll;

// 4 | -2 3 4 -3 --> Max(2) = max(Max(1), min

ll kq(int n, vector<int> &a){
	if(n == 0) return 0;
	
	ll max_v = a[0], curmax = a[0], curmin = a[0];
	for(int i = 1; i < n; ++i){
		ll num = (ll)a[i];
		ll tempm = curmax;
		curmax = max(num, max(num*curmax, num*curmin));
		curmin = min(num, min(num*tempm, num*curmin));
		
		max_v = max(max_v, curmax);
	}
	
	return max_v;
}

int main(){
	cin >> n;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	cout << kq(n, a);        