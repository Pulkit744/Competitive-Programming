#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> color;
bool ok = true;

void go(int u, int col) {
    color[u] = col;
    for (int v : c[u]) {
        if (color[v] == 0) {
            go(v, 3 - col);
        } else if (color[v] == col) {
            ok = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    c.resize(n + 1);
    color.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) go(i, 1);
    }
    if (!ok) {
        cout <<"IMPOSSIBLE";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << " ";
        }
        cout << "\n";
    }
}
