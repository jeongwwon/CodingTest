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
		if (visited[turn % 2][b]) { //수빈이가 1번 턴(1)에서 방문을 했고 2번턴(0)에 동생이 도착한다면 충족x, 3번턴(1)에 충족
			ok = true;
			cout <<"turn:"<<turn <<"," << "마지막:" << turn % 2 << "번," << b << "번 인덱스에 추가된 값 : " << visited[turn % 2][b] << "\n";
			break;
		}
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front();
			q.pop();
			for (int nx : {x + 1, x - 1, x * 2}) {
				if (nx<0 || nx>max_n || visited[turn % 2][nx])continue;
				cout <<"b값:"<<b<<"," << "turn:" << turn << "," << "방문점:" <<  nx << "\n";
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				cout<<turn%2<<"번," <<nx<<"번 인덱스에 추가된 값 : " << visited[turn % 2][nx] << "\n";
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