#include <bits/stdc++.h>
using namespace std;

int n, S;

int main(){
	cin >> n >> S;
	vector<int> w(n), v(n);
	
	for(int i = 1; i <= n; ++i)	cin >> w[i];
	for(int i = 1; i <= n; ++i)	cin >> v[i];
	
	vector<vector<int>> mat(n+1, vector<int>(S+1, 0));
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= S; ++j){
			mat[i][j] = mat[i-1][j];
			if(j >= w[i]) mat[i][j] = max(mat[i][j], mat[i-1][j - w[i]] + v[i]);
		}
	}
	
	cout << mat[n][S];
}