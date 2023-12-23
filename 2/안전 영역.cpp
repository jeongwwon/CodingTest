#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n = 101;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int visited[max_n][max_n];
int arr[max_n][max_n], arr2[max_n][max_n];
void dfs(int from, int to ,int depth) {
	visited[from][to] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = from + dy[i];
		int nx = to + dx[i];
		if (ny < 0 || nx < 0 || n <= ny || n <= nx || arr2[ny][nx] <= depth) continue;
		if (visited[ny][nx] == 1) continue;
		dfs(ny, nx, depth);
	}
}
int main() {
	int temp=0, count=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
		}
	}
	int cnt = 100;
	while (cnt--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr2[i][j] <= cnt || visited[i][j]) continue;
				dfs(i, j, cnt);
				temp++;
			}
		 }
			if (count < temp) {
				count = temp;
			}
			temp = 0;
			fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr2[i][j] = arr[i][j];
				}
			}
		}
	cout << count;
}