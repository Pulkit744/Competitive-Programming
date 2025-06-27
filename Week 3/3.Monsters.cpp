#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, time;
    string path;
};

int n, m;
vector<vector<char>> grid;
vector<vector<int>> monsterTime;
vector<vector<bool>> visited;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char mv[] = {'U', 'D', 'L', 'R'};

void bfs_monsters(queue<State>& q) {
    while (!q.empty()) {
        State s = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i], ny = s.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#' && monsterTime[nx][ny] > s.time + 1) {
                monsterTime[nx][ny] = s.time + 1;
                q.push({nx, ny, s.time + 1, ""});
            }
        }
    }
}

string bfs_escape(int startX, int startY) {
    queue<State> q;
    q.push({startX, startY, 0, ""});
    visited[startX][startY] = true;
    while (!q.empty()) {
        State s = q.front();
        q.pop();
        if (s.x == 0 || s.y == 0 || s.x == n - 1 || s.y == m - 1) {
            return "YES\n" + to_string(s.path.size()) + "\n" + s.path;
        }
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i], ny = s.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] &&
                grid[nx][ny] != '#' && s.time + 1 < monsterTime[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, s.time + 1, s.path + mv[i]});
            }
        }
    }
    return "NO";
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    monsterTime.assign(n, vector<int>(m, 1e6));
    visited.assign(n, vector<bool>(m, false));
    queue<State> monsterQueue;
    int startX, startY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                monsterQueue.push({i, j, 0, ""});
                monsterTime[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }
    bfs_monsters(monsterQueue);
    cout << bfs_escape(startX, startY) << endl;
}