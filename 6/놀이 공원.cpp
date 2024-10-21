#include<bits/stdc++.h>
using namespace std;
#define max_n 60000000004
#define MAX_M 10004
typedef long long ll;
ll n, m, a[MAX_M], lo, hi = max_n, ret, mid, temp;
bool check(ll mid) {
	temp = m; // 4분이 놀이기구중 max 시간이라면 4분이 경과했을때 
	for (ll i = 0; i < m; i++) temp += mid / a[i]; // 이분탐색의 시간으로 나누어 몇명의 사람이 타는지 temp에 더함
	return temp >= n; // 사람수가 만족한다면 true
}
int main() {
	cin >> n >> m;
	for (ll i = 0; i < m; i++)cin >> a[i];
	if (n <= m) {
		cout << n; return 0;
	}
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			hi = mid - 1;
			ret = mid; //ret은 시간
		}
		else lo = mid + 1;
	}
	temp = m; // temp는 놀이기구 탑승한 사람 수
	for (ll i = 0; i < m; i++) temp += ((ret - 1) / a[i]); // 해당 시간 -1 에서 몇명이 탔는지 계산

	for (ll i = 0; i < m; i++) {
		if (ret % a[i] == 0) temp++; // 해당 시간과 정확히 나누어 떨어진다면 탑승자 ++
		if (temp == n) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
}