#include<bits/stdc++.h>
#define prev aaa
#define next aa
using namespace std;
const int MAX = 200004;
int visited[MAX + 4];
int prev[MAX + 4];
queue<int>q;
vector<int>v;
int main() {
	int n, m;
	cin >> n >> m;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == m) {
			break;
		}
		for (int next : {here - 1, here + 1, here * 2}) {
			if (0 <= next && next <= MAX) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = visited[here]+ 1;
					prev[next] = here;
				}
			}
		}
	}
	for (int i = m; i != n; i = prev[i]) {
		v.push_back(i);
	}
	v.push_back(n);
	cout << visited[m] - 1 << "\n";
	reverse(v.begin(), v.end());
	for (int there : v) {
		cout << there << " ";
	}
	cout << "\n";
}