#include<bits/stdc++.h>
using namespace std;
int a[3][3] = {
	{10, 20, 21},
	{70, 90, 12},
	{80, 110, 120}
};
int visited[3][3];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
void go(int from, int to,int sum) {
	visited[from][to] = 1;
	if (from == 2 && to == 2) {
		cout <<sum << "\n";
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = from + dy[i];
		int nx = to + dx[i];
		if (ny < 0 || nx < 0 || 3 <= ny || 3 <= nx || visited[ny][nx] == 1) continue;
		sum += a[ny][nx];
		go(ny, nx,sum);
		visited[ny][nx] = 0;
		sum -= a[ny][nx];
	}
}
int main() {
	visited[0][0] = 1;
	go(0, 0,a[0][0]);


}