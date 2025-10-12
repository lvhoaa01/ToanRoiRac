#include <bits/stdc++.h>
using namespace std;

bool sinhtohop(vector<int> &a, int n, int k){
	int i = k - 1;
	while(i){
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
	
	if(sinhtohop(a, n, k))
		for(int x : a) cout << x << " ";
	else cout << "Đã là tổ hợp cuối";
}