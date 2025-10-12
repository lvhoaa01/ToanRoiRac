#include <bits/stdc++.h>
using namespace std;

// Khởi tạo biến đầu -> Sinh -> Lặp -> Gặp biến cuối thì dừng -> Lấy 1 biến làm check

int n, a[100], ok,k;

void khoitao(){
	for(int i = 1; i <= n; ++i){
		a[i] = 0;
	}
}

void sinh(){
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		--i;
	}
	
	if(i == 0)	ok = 0;
	else a[i] = 1;
}
bool check(){           // TH bài cho chỉ in những bit có số k là bit 1
	int cout = 0;
	for(int i = 1; i <= n; ++i)
		cout += a[i];
	return cout == k;
}

int main(){
	cin >> n;
	ok = 1;
	khoitao();
	while(ok){
		for(int i = 1; i <= n; ++i)
			cout << a[i];
		cout << endl;
		sinh();
		
	}
}