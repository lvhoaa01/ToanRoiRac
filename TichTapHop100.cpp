#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_H 300   

void multi(int re[], int x) {
    int cor = 0;
    for (int i = 0; i < MAX_H; ++i) {
        long long curV = 1LL * re[i] * x + cor;
        re[i] = curV % 10;
        cor = curV / 10;
    }
}

int compare_two(int a[], int b[]) {
    for (int i = MAX_H - 1; i >= 0; --i) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

void copy_two(int dest[], int src[]) {
    for(int i = 0; i < MAX_H; ++i) dest[i] = src[i];
}

void In(int a[]) {
    int i = MAX_H - 1;

    while (i > 0 && a[i] == 0) --i;
    
    if (i == 0 && a[i] == 0) {
        cout << 0;
        return;
    }

    for (; i >= 0; --i) cout << a[i];
}

int main() {

    int n;cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    int max_V[MAX_H];
    memset(max_V, 0, sizeof(max_V));

    max_V[0] = -1;  

    for (int i = 0; i < n; ++i) {
        int cur[MAX_H];
        memset(cur, 0, sizeof(cur));
        cur[0] = 1; 

        for (int j = i; j < n; ++j) {
            multi(cur, a[j]);

            if (compare_two(cur, max_V) > 0) {
                copy_two(max_V, cur);
            }
        }
    }

    In(max_V);
}