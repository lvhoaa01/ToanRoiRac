#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;
vector<bool> visited;

void dfs(int u){
	visited[u] = true;
	
	for(int v = 0; v < n; ++v){
		if(G[u][v] == 1 && !visited[v])
			dfs(v);
	}
}

bool isLT(){
	dfs(0);
	for(int i = 0; i < n; ++i){
		if(!visited[i]) return false;
	}
	
	return true;
}

int main(){
	cin >> n;
	G.assign(n, vector<int>(n));
	visited.assign(n, false);
	
	for(auto &x : G)
		for(int &i : x)
			cin >> i;
			
			
	if(isLT()) cout << "lien thong\n";
	else cout << "khong lien thong\n";
}