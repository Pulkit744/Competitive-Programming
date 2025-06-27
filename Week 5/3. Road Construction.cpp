#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, sz;
    int components;
    int max_size;
    DSU(int n): n(n), parent(n+1), sz(n+1, 1) {
        components = n;
        max_size = (n > 0 ? 1 : 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    } 
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;
        // union by size
        if (sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        components--;
        max_size = max(max_size, sz[ra]);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
        cout << dsu.components << " " << dsu.max_size;
        if (i + 1 < m) cout << '\n';
    }
}
