#include<bits/stdc++.h>
using namespace std;
int n, m,r,ret;
char a[6][6];
int visited[6][6];
int dy[4] = { -1,0,1,0 }, dx[4] = {0,1,0,-1};

void go(int y, int x) {
	if (y == 0 && x == m-1 && visited[y][x] == r) {
		ret += 1;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || n <= ny || m <= nx || visited[ny][nx])continue;
		if (a[ny][nx] == 'T')continue;
		visited[ny][nx] = visited[y][x] + 1;
		go(ny, nx);
		visited[ny][nx] = 0;
	}
}
int main() {
	cin >> n >> m>>r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	visited[n-1][0] = 1;
	go(n-1, 0);
	cout << ret;
}