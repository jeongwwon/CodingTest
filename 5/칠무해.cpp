#include<bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
#define f first
#define s second
typedef unsigned long long ll;
const int INF = 987654321;
int n;
double temp;
priority_queue<double>pq;
vector<double>v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (pq.size() == 7) {
			pq.push(temp); pq.pop();
		}
		else pq.push(temp);
	}
	while (pq.size()) {
		v.push_back(pq.top());
		pq.pop();
	}
	sort(v.begin(), v.end());
	for (double there : v) {
		printf("%.3lf\n", there);
	}
}