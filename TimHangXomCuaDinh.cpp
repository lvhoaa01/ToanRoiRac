#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin >> n;
	vector<vector<int>> G(n, vector<int>(n));
	for(auto &x : G)
		for(int &i : x)
			cin >> i;
	
	int src;cin >> src;
	
	vector<int> neighbors;
	for(int i = 0; i < n; ++i){
		if(G[src][i] != 0){
			neighbors.push_back(i);
		}
	}
	
	if(neighbors.empty()){
		cout << "none\n";
	}else{
		for(int i = 0; i < neighbors.size(); ++i){
			cout << neighbors[i];
			if(i < neighbors.size() - 1)
				cout << " ";
		}
		cout << "\n";
	}
}