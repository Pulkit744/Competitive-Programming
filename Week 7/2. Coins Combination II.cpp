#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main(){
    long long n,a;
    cin>>n>>a;
    vector<long long> coins(n);
    for (long long i=0;i<n;i++)
    cin>>coins[i];
    vector<int> count(a+1);
    count[0] = 1;
    for (auto c : coins) {
        for (long long x = c; x <= a; x++) {
    if (x-c >= 0) {
    count[x] = (count[x]+count[x-c])% MOD;
    }
    }  
    }
    cout<<count[a]<<'\n';
} 