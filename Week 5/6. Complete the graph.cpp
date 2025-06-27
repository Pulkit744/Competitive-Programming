#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

struct Edge { int u,v; ll w; };

int main(){
    int n,m,s,t;
    ll L;
    cin >> n >> m >> L >> s >> t;
    vector<Edge> E(m);
    vector<vector<pair<int,int>>> adj(n), adj_rev(n);
    for(int i=0;i<m;i++){
        cin >> E[i].u >> E[i].v >> E[i].w;
        adj[E[i].u].emplace_back(E[i].v,i);
        adj[E[i].v].emplace_back(E[i].u,i);
        adj_rev[E[i].v].emplace_back(E[i].u,i);
        adj_rev[E[i].u].emplace_back(E[i].v,i);
    }
    vector<ll> distT(n, INF);
    {
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        distT[t] = 0;
        pq.emplace(0,t);
        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d>distT[u]) continue;
            for(auto [v, ei] : adj_rev[u]){
                ll w = E[ei].w ? E[ei].w : INF;
                if(d + w < distT[v]){
                    distT[v] = d + w;
                    pq.emplace(distT[v], v);
                }
            }
        }
    }
    {
        vector<ll> d0(n, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        d0[s]=0; pq.emplace(0,s);
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop();
            if(d> d0[u]) continue;
            for(auto [v, ei]: adj[u]){
                ll w = E[ei].w ? E[ei].w : 1;
                if(d + w < d0[v]){
                    d0[v] = d + w;
                    pq.emplace(d0[v],v);
                }
            }
        }
        if(d0[t] > L){ cout<<"NO\n"; return 0; }
    }
    {
        if(distT[s] < L){ cout<<"NO\n"; return 0; }
    }
    vector<ll> distS(n, INF);
    vector<bool> seenZero(m,false);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    distS[s]=0; pq.emplace(0,s);
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d>distS[u]) continue;
        if(u==t) break;
        for(auto [v, ei]: adj[u]){
            ll w = E[ei].w;
            if(w==0){
                ll need = L - d - distT[v];
                if(need < 1) w = INF;
                else{
                    w = need;
                    if(!seenZero[ei]){
                        E[ei].w = w;
                        seenZero[ei]=true;
                    }
                }
            }
            if(d + w < distS[v]){
                distS[v] = d + w;
                pq.emplace(distS[v], v);
            }
        }
    }
    if(distS[t] != L){
        cout<<"NO\n";
        return 0;
    }
    for(int i=0;i<m;i++){
        if(E[i].w==0) E[i].w = INF;
    }
    cout<<"YES\n";
    for(auto &e: E){
        cout<<e.u<<" "<<e.v<<" "<<e.w<<"\n";
    }
    return 0;
}
