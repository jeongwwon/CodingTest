#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>>pqq;
priority_queue<int>pq;
int main() {
	for (int i = 0; i < 8; i++) {
		pq.push(i);
		pqq.push(i);
	}
	cout << "�Ϲ� Priority queue\n";
	while (pq.size()) {
		int there = pq.top();
		pq.pop();
		cout << there << "\n";
	}
	cout << "�������� Priority queue\n";
	while (pqq.size()) {
		int there = pqq.top();
		pqq.pop();
		cout << there << "\n";
	}
}