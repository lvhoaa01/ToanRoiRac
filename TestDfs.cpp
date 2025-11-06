#include <bits/stdc++.h>
using namespace std;
// NQueen dùng chéo chính phụ
int n, dem = 0;
vector<bool> visited, dig1, dig2;

void Try(int r){
    if(r == n){
        ++dem;
        return;
    }
    for(int c = 0; c < n; ++c){
        if(!visited[c] && !dig1[c+r] && !dig2[r - c + n - 1]){
            visited[c] = true;
            dig1[c+r] = true;
            dig2[r - c + n - 1] = true;

            Try(r+1);

            visited[c] = false;
            dig1[c+r] = false;
            dig2[r - c + n - 1] = false;
        }
    }
}

int main(){
    cin >> n;

    visited.resize(n, false);
    dig1.resize(2*n-1, false);
    dig2.resize(2*n-1, false);
    Try(0);
    cout << dem;
}
