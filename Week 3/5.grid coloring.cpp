#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) 
        cin >> grid[i];
    const string letters = "ABCD";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char orig = grid[i][j];
            for (char c : letters) {
                if (c == orig) continue;
                if (i > 0 && c == grid[i-1][j]) continue;
                if (j > 0 && c == grid[i][j-1]) continue;
                grid[i][j] = c;
                break;
            }
        }
    }
    for (auto a : grid)
        cout << a << "\n";
}
