#include<bits/stdc++.h>

using namespace std;
vector<int> adj[1004];
int visited[1004];
void postOrder(int here) {
	if (visited[here] == false) {
		if (adj[here].size() == 0) {
			cout << here << " ";
			visited[here] = 1;
			return;
		}
		postOrder(adj[here][0]);
		postOrder(adj[here][1]);
		cout << here << " ";
		visited[here] = 1;
	}
}
void preOrder(int here) {
	if (visited[here] == false) {
		if (adj[here].size() == 0) {
			cout << here << " ";
			visited[here] = 1;
			return;
		}
		cout << here << " ";
		visited[here] = 1;
		preOrder(adj[here][0]);
		preOrder(adj[here][1]);
	}
}
void inOrder(int here) {
	if (visited[here] == false) {
		if (adj[here].size() == 0) {
			cout << here << " ";
			visited[here] = 1;
			return;
		}
		inOrder(adj[here][0]);
		cout << here << " ";
		visited[here] = 1;
		inOrder(adj[here][1]);
	}
}

int main() {
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	int root = 1;
	cout << "\nƮ����ȸ : postOrder\n";
	postOrder(root); memset(visited, 0, sizeof(visited));
	cout << "\nƮ����ȸ : preOrder\n";
	preOrder(root); memset(visited, 0, sizeof(visited));
	cout << "\nƮ����ȸ : inOrder\n";
	inOrder(root); memset(visited, 0, sizeof(visited));
	return 0;
}