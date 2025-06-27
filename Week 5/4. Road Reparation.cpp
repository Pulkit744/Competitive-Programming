#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> p,r;
    DSU(int n):p(n+1),r(n+1){
    iota(p.begin(),p.end(),0);
}
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}
bool unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return false;
    if(r[a]<r[b])swap(a,b);
    p[b]=a;
    if(r[a]==r[b])r[a]++;
    return true;
}
};
int main(){
    int n,m;
    cin>>n>>m;
    struct Edge{
        int u,v;
        long long w;
    };
    vector<Edge> e(m);
    for(int i=0;i<m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e.begin(),e.end(),[](auto &a,auto &b){
        return a.w<b.w;
    });
    DSU d(n);
    long long cost=0;
    int cnt=0;
    for(auto &ed:e) if(d.unite(ed.u,ed.v)){
        cost+=ed.w; 
        if(++cnt==n-1) break;
    }
    if(cnt!=n-1) cout<<"IMPOSSIBLE\n"; else cout<<cost<<"\n";
}
