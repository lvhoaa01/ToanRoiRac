#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> d(n + 1, 0);
    d[0] = 1;
    for (int coin : {50, 100, 200}) {
        for (int i = coin; i <= n; i++) {
            d[i] += d[i - coin];
        }
    }
    cout << d[n] << endl;
    return 0;
}
