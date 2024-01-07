#include<bits/stdc++.h>

using namespace std;
vector<int>adj[10001];
int visited[10001];
int n,m,mx;
int dp[10001];
int A, B;
int dfs(int here) {
	int ret = 1;
	visited[here] = 1;
	for (int there : adj[here]) {
		if (visited[there])continue;
		ret += dfs(there);
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> A >> B;
		adj[B].push_back(A);
	}
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + 10001, 0);
		dp[i] = dfs(i);
		mx = max(dp[i], mx);
	}
	for (int i = 1; i <= n; i++) {
		if (mx == dp[i]) {
			cout << i << " ";
		}
	}
}