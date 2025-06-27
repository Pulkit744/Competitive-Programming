#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> labyrinth(n, vector<char>(m));
    vector<vector<Cell>> parent(n, vector<Cell>(m, {-1, -1}));    
    int startX, startY, endX, endY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') startX = i, startY = j;
            if (labyrinth[i][j] == 'B') endX = i, endY = j;
        }
    }
    queue<Cell> q;
    q.push({startX, startY});
    labyrinth[startX][startY] = '#';
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char move[] = {'U', 'D', 'L', 'R'};
    bool found = false;
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();
        if (current.x == endX && current.y == endY) {
            found = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i], ny = current.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && labyrinth[nx][ny] != '#') {
                q.push({nx, ny});
                labyrinth[nx][ny] = '#'; 
                parent[nx][ny] = {current.x, current.y}; 
            }
        }
    }
    if (!found) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    string path;
    for (int x = endX, y = endY; !(x == startX && y == startY);) {
        Cell prev = parent[x][y];
        for (int i = 0; i < 4; i++) {
            if (prev.x + dx[i] == x && prev.y + dy[i] == y) {
                path += move[i];
                break;
            }
        }
        x = prev.x;
        y = prev.y;
    }
    reverse(path.begin(), path.end());
    cout << path.length() << "\n" << path << endl;
}