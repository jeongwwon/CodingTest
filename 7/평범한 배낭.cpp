#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int n, k, w, v;
// 요소를 1개만 사용 가능한 dp 문제는 
// 오른쪽 끝부터 탐색하며 해당 무게에 대한 값을 갱신하지 않은 j-w를 참조하기 때문에 1번만 사용되게 계산된다.
// 각 반복문마다 새로운 무게가 주어지고 오른쪽부터 탐색하므로 각 아이템은 누적해서 사용되지 않는다.
int main() {
	scanf("%d %d", &n, &k);
	while (n--) {
		scanf("%d %d", &w, &v);
		for (int j = k; j >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
			cout << "j:" << j << "," << "dp[" << j << "]:" << dp[j] << ", dp["<<j-w<<"] 값 확인\n";
		}
	}
	printf("%d\n", dp[k]);
}