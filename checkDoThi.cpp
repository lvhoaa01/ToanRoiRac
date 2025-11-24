#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
    int a[105][105];
    if (scanf("%d", &n) <= 0) return 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int la_vo_huong = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                la_vo_huong = 0;
              break;
            }
        }
        if (la_vo_huong == 0)
          break;
    }
    
    if(la_vo_huong) cout << "vo_huong";
    else cout << "co_huong";
}