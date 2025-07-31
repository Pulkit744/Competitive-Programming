#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
    int reach =0;
    for(int i=0;i<nums.size();i++){
        if (i>reach)
        return false;
        else
        reach=max(reach,i+nums[i]);
    }    
    return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution sol;
    bool result = sol.canJump(nums);
    cout << result <<'\n';
}