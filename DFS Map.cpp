#include<bits/stdc++.h>
using namespace std;
const int V = 100;
int mp[V][V];
int visited[V][V];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int x ,  y ;
int cnt;
void go(int y,int x) {
	cout << y << "," << x << "\n";
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || V <= nx || V <= ny) continue;
		else if (visited[ny][nx] == 1)continue;
		else if (mp[ny][nx] == 0) continue;
		else { 
			go(ny, nx);
		}
	}
}
int main() {
	mp[0][0] = 1; mp[0][2] = 1; mp[0][4] = 1;
	mp[1][0] = 1; mp[1][1] = 1; mp[1][4] = 1;
	mp[2][3] = 1; mp[2][4] = 1; 
	mp[3][3] = 1; mp[3][4] = 1; 
	mp[4][1] = 1;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (visited[i][j] == 1 || mp[i][j]==0 )continue;
			go(i, j);
			cnt++;
		}
	}
	cout << cnt;
}