#include<bits/stdc++.h>
#define home jeongwon
using namespace std;
int n, m, a[54][54], result = 987654321;
vector<vector<int>>chickenList;
vector<pair<int, int>>home, chicken;
void combi(int start, vector<int>v) {
	if (v.size() == m) {
		chickenList.push_back(v);
		return;
	}
	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1)home.push_back({ i,j });
			if (a[i][j] == 2)chicken.push_back({ i,j });
		}
	}
	vector<int>v;
	combi(-1, v);
	for (vector<int>cList : chickenList) {
		int ret = 0;
		for (pair<int, int>_home : home) { //��������� ���� ġŲ���� �ϴ��� ������ �ȴ�
			int _min = 987654321;
			for (int ch : cList) { //���� �����Ǵ� ��� ġŲ���� ���� ���� �Ÿ� ���� ġŲ�� ����
				int _dist = abs(_home.first - chicken[ch].first) + abs(_home.second - chicken[ch].second);
				_min = min(_min, _dist);
			}
			ret += _min;
		}
		result = min(result, ret); //��� ġŲ�� ���� ������ ���� ������ ����
	}
	cout << result << "\n";
}