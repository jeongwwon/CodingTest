#include<bits/stdc++.h>
using namespace std;
#define max_n 60000000004
#define MAX_M 10004
typedef long long ll;
ll n, m, a[MAX_M], lo, hi = max_n, ret, mid, temp;
bool check(ll mid) {
	temp = m; // 4���� ���̱ⱸ�� max �ð��̶�� 4���� ��������� 
	for (ll i = 0; i < m; i++) temp += mid / a[i]; // �̺�Ž���� �ð����� ������ ����� ����� Ÿ���� temp�� ����
	return temp >= n; // ������� �����Ѵٸ� true
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
			ret = mid; //ret�� �ð�
		}
		else lo = mid + 1;
	}
	temp = m; // temp�� ���̱ⱸ ž���� ��� ��
	for (ll i = 0; i < m; i++) temp += ((ret - 1) / a[i]); // �ش� �ð� -1 ���� ����� ������ ���

	for (ll i = 0; i < m; i++) {
		if (ret % a[i] == 0) temp++; // �ش� �ð��� ��Ȯ�� ������ �������ٸ� ž���� ++
		if (temp == n) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
}