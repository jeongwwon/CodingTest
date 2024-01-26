#include<iostream>
#include<algorithm>
using namespace std;

char a[26][26];
int n, m,ret=-1;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
void go(int y, int x, int cnt, int num) {
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || n <= ny || m <= nx)continue;
		int _next = (1 << (int)(a[ny][nx] - 'A'));
		if ((_next & num) == 0) {
			go(ny	, nx, cnt + 1, num |= _next);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	go(0, 0, 1, 1<<(int)(a[0][0] - 'A'));
	cout << ret << "\n";
}