#include<bits/stdc++.h>
using namespace std;
const int V = 10;
vector<int> adj[10];
int visited[V];
void go(int from) {
	visited[from] = 1;
	cout << from << "\n";
	for (int n : adj[from]) {
		if (visited[n])continue;
		if (visited[n] == 0) {
			go(n);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	adj[1].push_back(2); adj[2].push_back(1);
	adj[1].push_back(3); adj[3].push_back(1); 
	adj[3].push_back(4); adj[4].push_back(3);
	for (int i = 0; i < V; i++) {
		for (int j : adj[i]) {
			if ( adj[i].size() && visited[i] == 0) {
				go(i);
			}
		}
	}




}