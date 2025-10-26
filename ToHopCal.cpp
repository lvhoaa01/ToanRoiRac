#include <bits/stdc++.h>
using namespace std;

string multi(string num, int x){
	int carry = 0;
	string result = "";
	
	for(int i = num.size()-1; i >= 0; --i){
		int prod = (num[i] - '0') * x + carry;
		carry = prod / 10;
		result += (prod%10) + '0';
	}
	
	while(carry){
		result += (carry%10) + '0';
		carry /= 10;
	}
	
	reverse(result.begin(), result.end());
	
	return result;
}

string div(string num, int x){
	string res = "";
	int carry = 0;
	
	for(int i = 0; i < num.size(); ++i){
		int curDigit = (num[i] - '0') + carry*10;
		res += (curDigit / x) + '0';
		carry = curDigit % x;
	}
	
	int count_0 = 0;
	while(count_0 < res.size() && res[count_0] == '0') count_0++;
	
	
	res.erase(0, count_0);
	if(res.empty()) return "0";
	return res;
}

string facto(int n, int k){
	string a1 = "1";
	for(int i = 0; i < k; ++i){
		a1 = multi(a1,n-i);
		a1 = div(a1, i+1);
	}
	return a1;
}

int main(){
	int n, k; cin >> n >> k;
	string res = facto(n, k);
	
	cout << res;
}