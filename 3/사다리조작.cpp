#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, h, a, b, ret = INF, visited[34][34];
bool check() {
	//가로줄을 기준으로 같은줄에 끝나는지 확인
	for (int i = 1; i < n; i++) {
		int start = i;
		//세로줄을 기준으로 i노드를 시작으로 증가할지 감소할지 방문 배열을 보고 check
		for (int j = 1; j <= h; j++) {
			if (visited[j][start])start++;
			else if (visited[j][start - 1])start--;
		}
		if (start != i) return false;
	}
	return true;
}
void go(int here, int cnt) {
	if (cnt > 3 || cnt >= ret)return;
	if (check()) {
		ret = min(ret, cnt);
		return;
	}
	//i는 가로줄 j는 세로줄 visited[i][j] 는 가로줄에서 건너가는지 체크
	for (int i = here; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])continue;
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}
int main() {
	//n: 세로줄  m:가로줄의 개수 h:가로줄
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		visited[a][b] = 1;
	}
	//cnt: 놓은 사다리 개수 ret=최대값
	go(1, 0);
	cout << ((ret == INF) ? -1 : ret) << "\n";
}