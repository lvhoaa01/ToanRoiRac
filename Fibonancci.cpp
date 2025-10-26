#include <bits/stdc++.h>
using namespace std;

long long int fibo(int h){
	if(h==0) return 0;
	if(h==1) return 1;
	long long int sum, res = 0, prev = 1;
	for(int i = 2; i <= h;++i){
		sum = res + prev;
		res = prev;
		prev = sum;
	}
	return sum;
}

int main(){
	int h; cin >> h;
	long long int res = fibo(h);
	cout << res;
}