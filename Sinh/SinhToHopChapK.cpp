#include <bits/stdc++.h>
using namespace std;
// n(5) k(3) 123 || 345 -> n-k+1, n-k+2, n-k+3
int n, k, a[100], ok;

void khoitao(){
	for(int i = 1; i <= k; ++i){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i){ // 123 -> ch?n ngay 3 do 3 chua max san ma
		--i;
	}
	if(i == 0) ok = 0;
	else{
		a[i]++;
		for(int j = i+1; j <= k; ++j){
			a[j] = a[j-1] + 1;
		}
	}
}

int main(){
	cin >> n >> k;
	ok = 1;
	khoitao();
	while(ok){
		for(int i = 1; i <= k; ++i)
			cout << a[i] << " ";
		cout << endl;
		sinh();
	}
}