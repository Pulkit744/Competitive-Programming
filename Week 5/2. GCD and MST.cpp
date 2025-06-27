#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p, sz;
    DSU(int n): p(n, -1), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll p;
        cin >> n >> p;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<ll,int>> ord(n);
        for (int i = 0; i < n; i++) {
            ord[i] = {a[i], i};
        }
        sort(ord.begin(), ord.end());
        DSU dsu(n);
        ll total_cost = 0;
        int used_edges = 0;
        for (auto &pr : ord) {
            ll val = pr.first;
            int idx = pr.second;
            if (val >= p) break;
            int j = idx - 1;
            while (j >= 0) {
                if (a[j] % val != 0) break;     
                if (dsu.find(j) == dsu.find(idx)) break; 
                dsu.unite(j, idx);
                total_cost += val;
                used_edges++;
                j--;
            }
            j = idx + 1;
            while (j < n) {
                if (a[j] % val != 0) break;
                if (dsu.find(j) == dsu.find(idx)) break;
                dsu.unite(j, idx);
                total_cost += val;
                used_edges++;
                j++;
            }
            if (used_edges == n - 1) break;
        }
        int rem = (n - 1) - used_edges;
        total_cost += rem * p;

        cout << total_cost << "\n";
    }
    return 0;
}