#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>moves(n,vector<int>(n, -1));
    moves[0][0]=0;
    int dx[]={2,2,1,1,-1,-1,-2,-2};
    int dy[]={1,-1,2,-2,2,-2,1,-1};
    vector<pair<int,int>>lef;
    lef.push_back({0,0});
    for(int i=0;i<lef.size();i++){
        int x=lef[i].first;
        int y=lef[i].second;
        for (int j=0;j<8;j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if (nx>=0 && ny>=0 && nx<n && ny<n && moves[nx][ny]==-1){
                moves[nx][ny]=moves[x][y]+1;
                lef.push_back({nx,ny});
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<moves[i][j]<<" ";
        }
        cout<<'\n';
    }
}