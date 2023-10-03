#include<bits/stdc++.h>

using namespace std;
const int V = 100;
int mp[V][V];
int visited[V][V];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
void bfs(int y,int x) {
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || V <= ny || V <= nx) continue;
			if (visited[ny][nx]) continue;
			if (mp[ny][nx] == 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	mp[0][0] = 1; mp[0][2] = 1; mp[0][4] = 1;
	mp[1][0] = 1; mp[1][1] = 1; mp[1][2] = 1; mp[1][4] = 1;
	mp[2][2] = 1; mp[2][3] = 1; mp[2][4] = 1;
	mp[3][2] = 1; mp[3][3] = 1; mp[3][4] = 1;
	mp[4][2] = 1; mp[4][3] = 1; mp[4][4] = 1;
	bfs(0, 0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}