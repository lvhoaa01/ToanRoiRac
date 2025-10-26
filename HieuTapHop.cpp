#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, m; cin >> n;
	vector<string> a(n);
	for(string &x : a) cin >> x;
	set<string> set1(a.begin(), a.end());
	vector<string> a1(set1.begin(), set1.end());
	cin >> m;
	vector<string> b(m);
	for(string &x : b) cin >> x;
	set<string> set2(b.begin(), b.end());
	vector<string> b1(set2.begin(), set2.end());
	
	
	vector<string> hieu;
	int i = 0, j = 0;
	while(i < a1.size() && j < b1.size()){
		if(a1[i] == b1[j]){
			++i;
			++j;
		}
		else if(a1[i] < b1[j]){
			hieu.push_back(a1[i]);
			++i;
		}
		else ++j;
	}
	while(i < a1.size()){
		hieu.push_back(a1[i]);
		++i;
	}

	if(hieu.empty()) cout << "none";
	else for(string &x : hieu) cout << x << " ";
}