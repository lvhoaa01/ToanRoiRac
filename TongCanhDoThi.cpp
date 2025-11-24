#include <stdio.h>
int main() {
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
    int socanh = 0;
    if (la_vo_huong == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0) { 
                    socanh += a[i][j];
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (a[i][j] != 0) {
                    socanh += a[i][j];
                }
            }
        }
    }
    printf("%d", socanh);
    return 0;
}