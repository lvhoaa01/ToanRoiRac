#include <bits/stdc++.h>
using namespace std;

int n;

void Fibo(){
    // Xử lý 2 trường hợp cơ sở
	if(n == 0){
		cout << 0;
		return;
	}
	if(n == 1){
		cout << 1;
		return;
	}
	
    // Bắt đầu tính từ F(2)
	long long prev = 0; // Đây là F(0)
	long long cont = 1; // Đây là F(1)
	
    // Vòng lặp tính F(i) dựa trên F(i-1) và F(i-2)
	for(int i = 2; i <= n; ++i){
		long long tmp = cont; // Giữ lại F(i-1)
		cont += prev;         // cont = F(i-1) + F(i-2) = F(i)
		prev = tmp;           // prev trở thành F(i-1) cho vòng lặp sau
	}
    
    // Sau vòng lặp, 'cont' là F(n)
	cout << cont;
}

int main(){
	cin >> n;
	Fibo();
	return 0;
}