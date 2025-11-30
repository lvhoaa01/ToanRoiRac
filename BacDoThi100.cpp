#include <bits/stdc++.h>

using namespace std;

int main() {


    int n; cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for(auto &x : a)
    	for(int &y : x) cin >> y;

    bool laVoHuong = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                laVoHuong = false;
                break;
            }
        }
        if (!laVoHuong) break;
    }

    if (laVoHuong) {
        for (int dinh = 0; dinh < n; ++dinh) {
            int bac = 0;
            for (int langGieng = 0; langGieng < n; ++langGieng) {
                bac += a[dinh][langGieng];
            }
            cout << bac;
            if (dinh < n - 1) cout << ";";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < n; ++i) {
            int banBacRa = 0;
            for (int j = 0; j < n; ++j) {
                banBacRa += a[i][j];
            }
            cout << banBacRa;
            if (i < n - 1) cout << ";";
        }
        cout << "\n";

        for (int i = 0; i < n; ++i) {
            int banBacVao = 0;
            for (int j = 0; j < n; ++j) {
                banBacVao += a[j][i];
            }
            cout << banBacVao;
            if (i < n - 1) cout << ";";
        }
        cout << "\n";
    }
}