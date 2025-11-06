#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3) return 0;
        int left = 0, right = n - 1;
        int maxleft = height[left], maxright = height[right];
        int totalwater = 0;
        while(left < right){
            if(maxleft < maxright){
                ++left;
                maxleft = max(maxleft, height[left]);
                totalwater += (maxleft - height[left]);
            }else{
                --right;
                maxright = max(maxright, height[right]);
                totalwater += (maxright - height[right]);
            }
        }
        return totalwater;
    }
};
int n;
vector<int> a;

int main(){
    Solution s;
    cin >> n;
    a.resize(n);
    for(int &x : a) cin >> x;
    int sum = s.trap(a);
    cout << sum;
}
