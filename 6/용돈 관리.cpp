#include<bits/stdc++.h>
using namespace std;
int n, m,a[100004],sum,mx,ret=987654321;
bool check(int mid) {
	if (mx > mid)return false;
	int cnt = 1;
	int temp = mid;
	for (int i = 0; i < n; i++) {  // mid�� ���� ũ�ٸ� cnt�� ������ �پ�� -> ���� ������ ���� mid�� ���� �ø�(lo���� mid+1) 
		if (mid - a[i] < 0) {       // �����Ѵٸ� mid���� �ٿ��� (=K) �ּҰ� Ž��
			cnt++;
			mid = temp;
		}
		mid -= a[i];
	}
	return cnt <= m;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		sum += a[i];
	}
	int lo = 1;
	int hi = sum;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			ret = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ret << "\n";
}