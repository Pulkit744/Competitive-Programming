#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<m;i++)
    cin>>b[i];
    vector<vector<int>> longest(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                longest[i][j]=longest[i-1][j-1] +1;
            }
            else{
                longest[i][j]=max(longest[i-1][j],longest[i][j-1]);
            }
        }
    }
    vector<int> seq;
    int i=n,j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            seq.push_back(b[j-1]);
            i--;
            j--;
        }
        else if (longest[i-1][j]>=longest[i][j-1])
        i--;
        else
        j--;
    }
    reverse(seq.begin(),seq.end());
    cout<<longest[n][m]<<'\n';
    for (int i=0;i<longest[n][m];i++)
    cout<<seq[i]<<" ";
    cout<<'\n';
}