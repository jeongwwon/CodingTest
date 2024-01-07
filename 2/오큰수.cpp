#include<bits/stdc++.h>
using namespace std;
int n, a[1000004], ret[1000004];
stack<int> s;
int main() {
	cin >> n;
	fill(ret, ret + 1000004, -1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (s.size() && a[s.top()] < a[i]) {
			ret[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}
}