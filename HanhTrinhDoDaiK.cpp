#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;
int count_n = 0;
int k;

void dfs_line(int src, int dest, int current_d){
	if(current_d == k){
		if(src == dest){
			++count_n;
			return;
		}
		return;
	}
	
	if(current_d > k) return;
	
	for(int v = 0; v < n; ++v){
		if(G[src][v]==1){
			dfs_line(v, dest, current_d+1);
		}
	}	
}

int main(){
	cin >> n;
	G.assign(n, vector<int> (n));
	for(auto &x : G)
		for(int &i : x)
			cin >> i;
	
	int src, dest;
	cin >> k >> src >> dest;
	
	dfs_line(src, dest, 0);
	
	cout << count_n;
}