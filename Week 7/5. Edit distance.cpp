#include <bits/stdc++.h>
using namespace std;

int main(){
    string A,B;
    cin>>A>>B;
    int n=A.size(),m=B.size();
    vector<vector<int>> ed(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
    ed[i][0]=i;
    for(int i=1;i<=m;i++)
    ed[0][i]=i;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]){
                ed[i][j]=ed[i-1][j-1];
            }
            else
            ed[i][j]=min({ed[i-1][j-1],ed[i][j-1],ed[i-1][j]})+1;
        }
    }
    cout<<ed[n][m]<<'\n';
}