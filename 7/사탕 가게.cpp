#include<bits/stdc++.h>
using namespace std;
int n,k,m1,m2,dp[100004];
int main() {
	while (1) {
		scanf("%d %d.%d", &n, &m1, &m2);
		int cost = m1 * 100 + m2;
		if (n == 0 && cost == 0) break;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			scanf("%d %d.%d", &k, &m1, &m2);
			int p = m1 * 100 + m2;
			for (int j = p; j <= cost; j++) {
				dp[j] = max(dp[j], dp[j - p] + k); //2�辿 ���� ex.700 ������ k ���� , 1400���� ����� 700 k+k�� ��ø�Ͽ� ����
			}
		}
		cout << dp[cost] << "\n";
	}
}