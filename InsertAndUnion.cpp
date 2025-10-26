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
	
	
	vector<int> hop, giao;
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()){
		if(a[i] == b[j]){
			hop.push_back(a[i]);
			giao.push_back(a[i]);
			++i;
			++j;
		}
		else if(a[i] < b[j]){
			hop.push_back(a[i]);
			++i;
		}
		else{
			hop.push_back(b[j]);
			++j;
		}
	}
	while(i < a.size()){
		hop.push_back(a[i]);
		++i;
	}
	while(j < b.size()){
		hop.push_back(b[j]);
		++j;
	}
	if(giao.size() == 0) cout<< "none";
	else{
		for(int k = 0; k < giao.size(); ++k){
			if(k == giao.size() - 1){
				cout << giao[k];
				break;
			}
			cout << giao[k] << " ";
		}
	}
	cout << endl;
	if(hop.size() == 0) cout<< "none";
	else{
		for(int x : hop) cout << x << " ";
	}
}