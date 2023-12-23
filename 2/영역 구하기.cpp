#include<bits/stdc++.h>
#define y1 aaaa
int m, n, k,x1,y1,x2,y2;
const int max_n = 101;	
int visited[max_n][max_n];
using namespace std;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<int> ret;
int dfs(int from, int to) {
	visited[from][to] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = from + dy[i];
		int nx = to + dx[i];
		if (ny < 0 || nx < 0 || m <= ny || n <= nx || visited[ny][nx] == 1)continue;
		ret += dfs(ny, nx);
	}
	return ret;
}
int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				visited[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 1)continue;
			ret.push_back(dfs(i, j));
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for (int a : ret) {
		cout << a << " ";
	}
}