#include <bits/stdc++.h>
using namespace std;

int n;
typedef long long ll;

ll kq(int n, vector<int> &a){
	if(n == 0) return 0;
	
	ll curmax = a[0], curmin = a[0], max_v = a[0];
	
	for(int i = 1; i < n; ++i){
		ll num = a[i];
		ll tempm = curmax;
		curmax = max(num, max(num*curmin, num*curmax));
		curmin = min(num, max(num*tempm, num*curmin));
		max_v = max(curmax, max_v);
	}
	return max_v;
}

int main(){
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	cout << kq(n, a);
}