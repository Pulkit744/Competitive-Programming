#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,s;
    cin>>n>>s;
    vector<int> price(n),pages(n);
    for(int i=0;i<n;i++)
    cin>>price[i];
    for(int i=0;i<n;i++)
    cin>>pages[i];
    vector<long long> m(s+1,0);
    for(int i=0;i<n;i++){
        for(int c=s;c>=price[i];c--)
        m[c]= max(m[c],m[c-price[i]]+pages[i]);
    }
    long long f=0;
    for(int i=1;i<=s;i++)
    f=max(f,m[i]);
    cout<<f<<'\n';
}