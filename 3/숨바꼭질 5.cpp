#include<bits/stdc++.h>
using namespace std;
const int max_n = 500000;
int visited[2][max_n + 4], a, b, ok, turn = 1;
int main() {
	cin >> a >> b;
	if (a == b) {
		cout << 0 << "\n";
		return 0;
	}
	queue<int>q;
	visited[0][a] = 1;
	q.push(a);
	while (q.size()) {
		b += turn;
		if (b > max_n)break;
		if (visited[turn % 2][b]) { //�����̰� 1�� ��(1)���� �湮�� �߰� 2����(0)�� ������ �����Ѵٸ� ����x, 3����(1)�� ����
			ok = true;
			cout <<"turn:"<<turn <<"," << "������:" << turn % 2 << "��," << b << "�� �ε����� �߰��� �� : " << visited[turn % 2][b] << "\n";
			break;
		}
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front();
			q.pop();
			for (int nx : {x + 1, x - 1, x * 2}) {
				if (nx<0 || nx>max_n || visited[turn % 2][nx])continue;
				cout <<"b��:"<<b<<"," << "turn:" << turn << "," << "�湮��:" <<  nx << "\n";
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				cout<<turn%2<<"��," <<nx<<"�� �ε����� �߰��� �� : " << visited[turn % 2][nx] << "\n";
				if (nx == b) {
					ok = 1;
					break;
				}
				q.push(nx);
			}
			if (ok)break;
		}
		if (ok)break;
		turn++;
	}
	if (ok)cout << turn << "\n";
	else cout << -1 << "\n";
}