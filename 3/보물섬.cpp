#include<bits/stdc++.h>
using namespace std;
int n, m;
char a[54][54];
char s;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int visited[54][54];
int ret2;
void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int,int>>q;
    q.push({ y,x });
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || n <= ny || m <= nx || a[ny][nx] == 'W') continue;
            if (visited[ny][nx])continue;
            visited[ny][nx] = visited[y][x] + 1;
            ret2=max(ret2,visited[ny][nx]);
            q.push({ ny,nx });
        }
    }
    return;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }
    cout << ret2-1 << "\n";
}