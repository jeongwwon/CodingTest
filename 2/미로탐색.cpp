#include<bits/stdc++.h>

using namespace std;
int n, m,num;
const int max_n = 104;
int a[max_n][max_n];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int visited[104][104];
void bfs(int from,int to) {
	int y=from, x=to;
	queue<pair<int, int>> q;
	q.push({ from,to });
	while (q.size()) {
		tie(y,x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || n < ny || m < nx || a[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}
int main() {
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &a[i][j]);
		}
	}
	visited[0][0] = 1;
	bfs(0,0);
	cout << visited[n-1][m-1];
}