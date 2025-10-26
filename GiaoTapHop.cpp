// Giao c?a 2 t?p h?p A B

#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, m; cin >> n;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	sort(a.begin(), a.end());
	cin >> m;
	vector<int> b(m);
	for(int &x : b) cin >> x;
	sort(b.begin(), b.end());
	
	
	vector<int> giao;
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()){
		if(a[i] == b[j]){
			giao.push_back(a[i]);
			++i;
			++j;
		}
		else if(a[i] < b[j]) ++i;
		else ++j;	
	}
	if(giao.size() == 0) cout<< "none";
	else{
		for(int x : giao) cout << x << " ";
	}
}