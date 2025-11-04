#include <bits/stdc++.h>
using namespace std;

int n, S;
vector<int> w;
vector<int> cursub;
int sub = 0;

void In(const vector<int>& subset, int sum) {
    sub++;
    cout << "Tap con " << sub << " (Tong = " << sum << "): { ";
    for (int i = 0; i < subset.size(); ++i) {
        cout << subset[i] << (i == subset.size() - 1 ? " " : ", ");
    }
    cout << "}\n";
}

void Try(int i, int curSum){
	if(i == n){
		In(cursub, curSum);
		return;
	}
	Try(i+1, curSum);
	
	if(curSum + w[i] <= S){
		cursub.push_back(w[i]);
		Try(i+1, curSum + w[i]);
		cursub.pop_back();
	}
}

int main(){
	cout << "Nhap N (so vat) va S (suc chua): ";
    cin >> n >> S;
    w.resize(n);

    cout << "Nhap " << n << " can nang:\n";
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    cout << "\n--- Liet ke cac tap con hop le ---\n";
    
    // Bắt đầu từ vật 0, tổng ban đầu là 0
    // Ta dùng phiên bản "Standard" vì nó dễ hiểu hơn
    Try(0, 0);
    
    if (sub == 0) {
        cout << "Khong tim thay tap con nao hop le.\n";
    }

    return 0;
}