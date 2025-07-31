#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
        return 0;
        sort(points.begin(),points.end(),[](auto &a, auto &b){return a[1]<b[1];});
        int arrows =1;
        int ri=points[0][1];
        for(int i=1;i<points.size();i++){
            int lef=points[i][0];
            if (lef>ri){
                arrows++;
                ri=points[i][1];
            }
        }
        return arrows;
    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<int>> points(n);
    for(int i=0;i<n;i++)
    cin>>points[i][0]>>points[i][1];
    Solution sol;
    int result = sol.findMinArrowShots(points);
    cout << result << endl;
}