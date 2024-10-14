#include<bits/stdc++.h>
using namespace std;
#define first f
#define second s
typedef long long ll;
ll n, m, a[300004], ret = 1e18;
bool check(ll mid) {
	ll num = 0;
	for (int i = 0; i < m; i++) {
		num += a[i] / mid;
		if (a[i] % mid)num++;
	}
	return num <= n;
}
int main() {
	cin >> n >> m;
	ll lo = 1, hi = 0, mid;
	for (int i = 0; i < m; i++) {
		cin >> a[i]; 
		hi = max(hi, a[i]);
	} 
	while (lo <= hi) {  
		mid = (lo + hi) / 2; // 색이 다른 공을 줘야하기 때문에 가장 큰값 부터 이분 탐색
		if (check(mid)) {  //충족이 안된다는것은 작은 범위로 나누기 때문에 여분의 공이 존재 -> 나누는 수를 늘리는 lo를 증가 시킴
			ret = min(mid, ret); 
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret << "\n";
}