#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret, temp;
stack<pair<ll, ll>>s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		int cnt = 1;
		while (s.size() && s.top().first <= temp) {
			ret += s.top().second;  //ret�� stack�� �ִ� cnt������ �����ָ鼭 ¦���� ���� ����
			//cout << "ret��:" << ret << "\n";
			if (s.top().first == temp) {
				cnt = s.top().second + 1;
			}
			else {
				cnt = 1;
			}
			s.pop(); //temp�� ū���� ���Ա� ������ ���� stack�� pop���ش�.(������ ���� ���� ����)
		}
		if (s.size())ret++;
		//cout << "ret��:" << ret << "\n";
		s.push({ temp,cnt });
		//cout << "temp:" << temp << "," << "cnt:" << cnt << "\n";
	}
	cout << ret << "\n";
}
