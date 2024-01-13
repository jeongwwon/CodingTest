#include<bits/stdc++.h>
const int INF = 987654321;
using namespace std;
int n, m;
int person[1004][1004],fire[1004][1004];
char a[1004][1004];
int y, x, sy, sx;
vector<pair<int, int>>F;
char c;
int ret;
pair<int, int>J;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
bool in(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < m;
}
int main() {
	cin >> n >> m;
	fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == 'J') {
				sy = i;
				sx = j;
			}
			else if (c == 'F') {
				fire[i][j] = 1;
				q.push({ i,j });
			}
			a[i][j] = c;
		}
	}
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx))continue;
			if (fire[ny][nx] != INF || a[ny][nx] == '#')continue;
			fire[ny][nx] = fire[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	person[sy][sx] = 1;
	q.push({ sy,sx });
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		if (x == m - 1 || y == n - 1 || x == 0 || y == 0) {
			ret = person[y][x];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx))continue;
			if (person[ny][nx] || a[ny][nx] == '#')continue;
			if (fire[ny][nx] <= person[y][x] + 1)continue;
			person[ny][nx] = person[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	if (ret != 0) {
		cout << ret << "\n";
	}
	else cout << "IMPOSSIBLE\n";
	
}