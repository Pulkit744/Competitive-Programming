#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
            prof +=prices[i]-prices[i-1];
        }
    return prof;   
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++)
    cin>>prices[i];
    Solution so;
    cout<<so.maxProfit(prices)<<'\n';
}