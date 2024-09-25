#include<bits/stdc++.h>
using namespace std;
#define time ff
int n, k, a[101][101], time, y, x, l,dir=1,visited[101][101],t,idx;
const int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
vector<pair<int, int>>_time;
deque<pair<int, int>>dq;
int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		a[--y][--x] = 1;
	}
	cin >> l;
	char c;
	for (int i = 0; i < l; i++) {
		cin >> t >> c;
		if (c == 'D')_time.push_back({ t,1 });
		else _time.push_back({ t,3 });
	}
	dq.push_back({ 0,0 });
	while (dq.size()) {
		time++;
		tie(y, x) = dq.front();
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || n <= ny || n <= nx || visited[ny][nx])break;
		if (!a[ny][nx]) {
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		else a[ny][nx] = 0;
		visited[ny][nx] = 1;
		dq.push_front({ ny,nx });
		if (_time[idx].first == time) {
			dir = (dir + _time[idx].second) % 4;
			idx++;
		}
	}
	cout << time << "\n";
}
