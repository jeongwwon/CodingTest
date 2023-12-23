#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
const int max_n = 104;
int n, m, a[max_n][max_n], visited[max_n][max_n],y,x,sy,sx,ey,ex;

int main() {
    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    queue<pair<int, int>> q;
    visited[sy][sx] = 1;
    q.push({ sy,sx });
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || m <= nx || n <= ny || a[ny][nx]==0) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x]+1;
            q.push({ ny,nx });
        }
    }
    printf("%d\n", visited[ey][ex]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "�ִ� �Ÿ�:" << visited[4][4] - 1 << '\n';
}