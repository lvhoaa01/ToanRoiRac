#include <bits/stdc++.h>
using namespace std;

void powell(int n, vector<vector<int>> &adj){
	vector<int> color(n, 0);//Đánh dấu màu
	vector<int> degree(n);//Bậc
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		degree[i] = adj[i].size(); // Bậc
		a[i] = i;
	}
	sort(a.begin(), a.end(), [&](int a, int b){
		return degree[a] > degree[b];
	});
	
	int curColor = 1;
	for(int i = 0; i < n; ++i){
		int u = a[i];
		if(color[u] != 0) continue;
		color[u] = curColor;
		for(int j = i + 1; j < n;++j){
			int v = a[j];
			if(color[v] == 0){
				bool conf = false;
				for(int k : adj[v]){
					if(color[k] == curColor){
						conf = true;
						break;
					}
				}
				if(!conf) color[v] = curColor;
			}
		}
		++curColor;
	}
	
	for(int i = 0; i < n; ++i){
        cout << "Đỉnh " << i << " có màu: " << color[i] << '\n';
    }

}

int main(){
	int n = 6;
	vector<vector<int>> adj(n);
	adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1, 3};
    adj[3] = {1, 2, 4, 5};
    adj[4] = {3, 5};
    adj[5] = {3, 4};

	powell(n, adj);
	return 0;
}