#include<bits/stdc++.h>
using namespace std;
int T,n, m,h;
int x, y;
const int max_n = 51;
int arr[max_n][max_n];
int visited[max_n][max_n];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void dfs(int from, int to) {
	visited[from][to] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = from + dy[i];
		int nx = to + dx[i];
		if (nx < 0 || ny < 0 || n < ny || m < nx || arr[ny][nx] == 0) continue;
		if (visited[ny][nx] == 1) continue;
		dfs(ny, nx);
	}
}
int main() {
	scanf("%d", &T);
	int *cnt = new int[T];
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &n, &m,&h);

		fill(&arr[0][0], &arr[0][0] + max_n * max_n, 0);
		fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);

		for (int j = 0; j < h; j++) {
			scanf("%d %d", &y, &x);
			arr[y][x] = 1;
		}
		int count = 0;
		for (int q = 0; q < n; q++) {
			for (int w = 0; w < m; w++) {
				if (visited[q][w] == 1 || arr[q][w] ==0 ) continue;
				dfs(q, w);
				count++;
			}
		}
		cnt[i] = count;
	}
	for (int i = 0; i < T; i++) {
		cout << cnt[i] << '\n';
	}
}