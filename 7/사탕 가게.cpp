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
				dp[j] = max(dp[j], dp[j - p] + k); //2배씩 부터 ex.700 까지는 k 저장 , 1400부터 저장된 700 k+k로 중첩하여 저장
			}
		}
		cout << dp[cost] << "\n";
	}
}