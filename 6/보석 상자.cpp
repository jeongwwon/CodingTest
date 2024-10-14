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
		mid = (lo + hi) / 2; // ���� �ٸ� ���� ����ϱ� ������ ���� ū�� ���� �̺� Ž��
		if (check(mid)) {  //������ �ȵȴٴ°��� ���� ������ ������ ������ ������ ���� ���� -> ������ ���� �ø��� lo�� ���� ��Ŵ
			ret = min(mid, ret); 
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret << "\n";
}