#include<bits/stdc++.h>
using namespace std;

const int dy[] = { 0, 1, 1 };  
const int dx[] = { 1, 1, 0 };

int n, a[17][17], dp[17][17][3];  // dp 배열을 3차원으로 사용 (가로, 대각선, 세로)

// ff, fs: 이전 위치, sf, ss: 현재 위치, 방향 dir (0: 가로, 1: 대각선, 2: 세로)
int go(int sf, int ss, int dir) {
    if (sf == n - 1 && ss == n - 1) {  // 도착점에 도달하면
        return 1;
    }
    int& ret = dp[sf][ss][dir];  
    if (ret != -1) return ret;

    ret = 0;  // 초기화

    // 현재 파이프의 방향에 따라 이동 가능한 경로 탐색
    for (int i = 0; i < 3; i++) {
        if ((dir == 0 && i == 2) || (dir == 2 && i == 0)) continue;  // 가로 -> 세로, 세로 -> 가로는 불가능
        int ny = sf + dy[i];
        int nx = ss + dx[i];

        if (ny >= n || nx >= n || a[ny][nx] == 1) continue;  // 범위를 벗어나거나 벽이면 건너뛰기
        if (i == 1 && (a[sf + 1][ss] == 1 || a[sf][ss + 1] == 1)) continue;  // 대각선은 추가적으로 벽 확인
        ret += go(ny, nx, i);  // 해당 경로로 재귀 호출
    }
    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j]; 
        }
    }
    memset(dp, -1, sizeof(dp));  
    cout << go(0, 1, 0) << "\n"; 
    cout << dp[0][1][0] << "\n";
}
