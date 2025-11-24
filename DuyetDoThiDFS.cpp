#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<bool> visited;
void dfs(int u){
	visited[u] = true;
	cout << u << " ";
	for(int i = 0; i < n; ++i){
		if(a[u][i] == 1 && !visited[i]){
			dfs(i);
		}
	}
}

int main(){
	cin >> n;
	a.assign(n, vector<int> (n));
	for(auto &x : a) 
		for(int &y : x) cin >> y;
	visited.assign(n, false);
	
	int bd;
	cin >> bd;
	dfs(bd);
}