#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long mx;
    cin>>n>>mx;
    vector<long long> w(n);
    for (int i=0;i<n;i++)
    cin>>w[i];
    sort(w.begin(),w.end());
    int g=0,i=0,j=n-1;
    while(i<=j){
        if (w[i]+w[j]<=mx){
            i++;j--;
        }
        else j--;
        g++;
    }
    cout<<g<<"\n";

}