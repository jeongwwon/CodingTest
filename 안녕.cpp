#include<bits/stdc++.h>
using namespace std;
int n, dp[101], hp[101], happy[101];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &hp[i]);
	for (int i = 0; i < n; i++) scanf("%d", &happy[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 100; j > hp[i]; j--) {
			dp[j] = std::max(dp[j], dp[j - hp[i]] + happy[i]);
		}
	}
	printf("%d\n", dp[100]);
}