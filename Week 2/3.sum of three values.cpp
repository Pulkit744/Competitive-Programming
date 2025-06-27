#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
     cin>>a[i].first;
    a[i].second=i+1;
    }
    sort(a.begin(),a.end());
    int j,k=n-1;
    for (int i=0;i<n-1;i++){
        j=i+1;
        k=n-1;
        while(j<k){
            if (a[i].first+a[j].first+a[k].first==x){
        cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<'\n';
        return 0;
        }
        else if (a[i].first+a[j].first+a[k].first>x)
        k--;
        else j++;
        }
    }
    cout<<"IMPOSSIBLE"<<'\n';
}