#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int dem = 0;

bool isafe(int row, int col, vector<vector<int>> &mat){
	int i, j;
	int n = mat.size();
	for(i = 0; i < row; ++i){
		if(mat[i][col]) return false;
	}
	for(i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
		if(mat[i][j]) return false;
	}
	for(i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j){
		if(mat[i][j]) return false;
	}
	return true;
}


void placeQueen(int row, vector<vector<int>> &mat, vector<vector<int>> &result){
	int n = mat.size();
	if(row == n){
		vector<int> ans;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(mat[i][j]){
					ans.push_back(j+1);
				}
			}
		}
		result.push_back(ans);
		return;
	}
	
	for(int i = 0; i < n; ++i){
		if(isafe(row, i, mat)){
			mat[row][i] = 1;
			placeQueen(row+1, mat, result);
			mat[row][i] = 0;
		}
	}
	return;
}

vector<vector<int>> NQueen(int n){
	vector<vector<int>> mat(n, vector<int>(n,0));
	vector<vector<int>> result;
	placeQueen(0, mat, result);
	return result;
}

int main(){
	int n; cin >> n;
	auto start = chrono::high_resolution_clock::now();
	vector<vector<int>> result = NQueen(n);
	auto stop = chrono::high_resolution_clock::now();
	for(auto &ans : result){
		for(auto i : ans){
			cout << i << " ";
		}
		cout << "\n";
		dem++;
	}
	auto duration = chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout << "Thoi gian thuc thi: " 
              << duration.count() << " ms" << endl;
	cout << dem;
	return 0;
}