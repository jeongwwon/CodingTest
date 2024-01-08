#include<bits/stdc++.h>
using namespace std;
vector<int>adj[4];
int visited[4];
vector<int>v;
void print() {
	for (int there : v) {
		cout << char(there+'A') << " ";
	}
	cout << "\n";
}
void go(int from) {
	if (v.size() == 3) {
		print();
		return;
	}
	for (int there : adj[from]) {
		if (visited[there] == 1)continue;
		visited[there] = 1;
		v.push_back(there);
		go(there);
		v.pop_back();
		visited[there] = 0;
	}
}
int main() {
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(0);
	adj[2].push_back(1);
	adj[3].push_back(1);

	visited[0] = 1;
	v.push_back(0);
	go(0);
}