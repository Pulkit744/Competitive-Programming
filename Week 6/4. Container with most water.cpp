#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ar=0;
        while(i<j){
        int h=min(height[i],height[j]);
        ar=max(ar,h*(j-i));
        if (height[i]>height[j])
        j--;
        else
        i++;
        }
        return ar;        
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];
    Solution sol;
    int result = sol.maxArea(height);
    cout << result << endl;
}