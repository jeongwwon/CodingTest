#include<bits/stdc++.h>
using namespace std;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
const int V = 3;
int mp[V][V];
int visited[V][V];
void go(int y,int x) {
	cout << y << "," << x << "\n";
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || V<=ny || V<=nx)  continue;
		if (visited[ny][nx])continue;
		if (mp[ny][nx]==0)continue;
		if (mp[y + dy[i]][x + dx[i]] && visited[y+dy[i]][x+dx[i]]==0) {
			go(ny,nx); // 0:위 1:오른쪽 2:아래 3: 왼쪽
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	mp[0][0] = 1;
	mp[1][0] = 1;
	mp[2][0] = 1;
	mp[2][1] = 1;
	mp[2][2] = 1;
	go(0, 0);
}