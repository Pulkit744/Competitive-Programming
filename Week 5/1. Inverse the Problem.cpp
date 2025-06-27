#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

int main(){
    int n;
    cin >> n;
    vector<vector<ll>> D(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> D[i][j];

    for(int i = 0; i < n; i++){
        if(D[i][i] != 0){ cout << "NO\n"; return 0; }
        for(int j = i+1; j < n; j++){
            if(D[i][j] != D[j][i] || D[i][j] == 0){
                cout << "NO\n"; return 0;
            }
        }
    }

    vector<bool> used(n);
    vector<ll> best(n, INF);
    vector<int> par(n, -1);
    used[0] = true;
    for(int i = 1; i < n; i++){
        best[i] = D[0][i];
        par[i] = 0;
    }
    vector<vector<pair<int,ll>>> T(n);
    for(int it = 1; it < n; it++){
        int u = -1;
        ll bv = INF;
        for(int i = 0; i < n; i++){
            if(!used[i] && best[i] < bv){
                bv = best[i];
                u = i;
            }
        }
        if(u < 0){ cout << "NO\n"; return 0; }
        used[u] = true;
        T[u].emplace_back(par[u], bv);
        T[par[u]].emplace_back(u, bv);
        for(int v = 0; v < n; v++){
            if(!used[v] && D[u][v] < best[v]){
                best[v] = D[u][v];
                par[v] = u;
            }
        }
    }
    vector<ll> dist(n);
    vector<int> stk; stk.reserve(n);
    for(int src = 0; src < n; src++){
        fill(dist.begin(), dist.end(), -1);
        dist[src] = 0;
        stk.clear();
        stk.push_back(src);
        while(!stk.empty()){
            int u = stk.back(); stk.pop_back();
            for(auto &e : T[u]){
                int v = e.first;
                if(dist[v] < 0){
                    dist[v] = dist[u] + e.second;
                    stk.push_back(v);
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(dist[j] != D[src][j]){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
