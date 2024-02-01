#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ret, temp1, temp;
int main() {
	cin >> n >> k;
	vector<pair<ll, ll>>v(n);
	vector<ll>vv(k);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < k; i++) {
		cin >> vv[i];
	}
	sort(v.begin(), v.end()); //���� �������� , ������ ������ ������
	sort(vv.begin(), vv.end()); //�賶���� ��������
	priority_queue<ll>pq;
	int j = 0;
	//�賶�� �������� ���������� j�� 0���� ���� ���ص��� == ���� �賶�� ������ �ִ� ������ ū�賶���� ������ �ְ� pq�� �����ֱ� ����
	for (int i = 0; i < k; i++) {
		while (j < n && v[j].first <= vv[i]) pq.push(v[j++].second); //v[j].first ���԰� ���� vv�� ���� �ʴ´ٸ� pq�� �ְ� j����
		//pq�� ������ ��� ��(v[j].second)�� top�� ���� �ǰ� pop
		if (pq.size()) {
			ret += pq.top(); pq.pop();
		}
	}
	cout << ret << "\n";
}