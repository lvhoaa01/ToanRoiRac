#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<bool> used;

void In(){
	for(int i = 1; i < n+1; ++i){
		cout << a[i];
	}
	cout << endl;
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(!used[j]){
			used[j] = true;
			a[i] = j;
			if(i == n) In();
			else Try(i+1);
			
			used[j] = false;
		}
	}
}

int main(){
	cin >> n;
	a.resize(n+1);
	used.resize(n+1, false);
	Try(1);
}