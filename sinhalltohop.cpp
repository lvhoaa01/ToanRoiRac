#include <bits/stdc++.h>
using namespace std;

bool checksinh(vector<int> &a, int n, int k){
	int i = k - 1;
	while(i>=0){
		if(a[i] < n - k + i + 1){
			++a[i];
			for(int j = i+1; j < k; ++j) a[j] = a[j-1] + 1;
			return true;
		}
		--i;
	}
	return false;
}

int main(){
	int n = 6, k = 3;
	vector<int> a = {1,2,3};
	for(int x : a) cout << x;
		cout << endl;
	do{
		for(int x : a) cout << x;
		cout << endl;
	}while(checksinh(a,n,k));
}