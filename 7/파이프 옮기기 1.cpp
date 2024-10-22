#include<bits/stdc++.h>
using namespace std;

const int dy[] = { 0, 1, 1 };  
const int dx[] = { 1, 1, 0 };

int n, a[17][17], dp[17][17][3];  // dp �迭�� 3�������� ��� (����, �밢��, ����)

// ff, fs: ���� ��ġ, sf, ss: ���� ��ġ, ���� dir (0: ����, 1: �밢��, 2: ����)
int go(int sf, int ss, int dir) {
    if (sf == n - 1 && ss == n - 1) {  // �������� �����ϸ�
        return 1;
    }
    int& ret = dp[sf][ss][dir];  
    if (ret != -1) return ret;

    ret = 0;  // �ʱ�ȭ

    // ���� �������� ���⿡ ���� �̵� ������ ��� Ž��
    for (int i = 0; i < 3; i++) {
        if ((dir == 0 && i == 2) || (dir == 2 && i == 0)) continue;  // ���� -> ����, ���� -> ���δ� �Ұ���
        int ny = sf + dy[i];
        int nx = ss + dx[i];

        if (ny >= n || nx >= n || a[ny][nx] == 1) continue;  // ������ ����ų� ���̸� �ǳʶٱ�
        if (i == 1 && (a[sf + 1][ss] == 1 || a[sf][ss + 1] == 1)) continue;  // �밢���� �߰������� �� Ȯ��
        ret += go(ny, nx, i);  // �ش� ��η� ��� ȣ��
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
