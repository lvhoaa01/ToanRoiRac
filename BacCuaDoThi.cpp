#include <bits/stdc++.h>
using namespace std;

bool check(int n, vector<vector<int>>& a){
	for(int i = 0; i < n; ++i){
		if(a[i][i] != 0) return false;
		for(int j = i+1; j < n;++j){
			if(a[i][j] != a[j][i]) return false;
		}
	}
	return true;
}

void solve(){
	int n; cin >>n;
	vector<vector<int>> a(n, vector<int> (n));
	for(auto &x : a) 
		for(int &y : x) cin >> y;
	if(check(n, a)){
		vector<int> bac;	
		for(int i = 0; i< n; ++i){
			int de = 0;
			for(int j = 0; j < n; ++j){
				de += a[i][j];
			}
			bac.push_back(de);
		}
		
		for(int i = 0; i< n; ++i){
			cout << bac[i];
			if(i < n-1) cout << ";";
		}
	}
	else{
		vector<int> out_bac(n, 0), in_bac(n, 0);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				out_bac[i] += a[i][j];
				in_bac[j] += a[i][j];
			}
		}
		
		for(int i = 0; i< n; ++i){
			cout << out_bac[i];
			if(i < n-1) cout << ";";
		}
		cout << endl;
		for(int i = 0; i< n; ++i){
			cout << in_bac[i];
			if(i < n-1) cout << ";";
		}
	}
}

int main(){
	solve();
}