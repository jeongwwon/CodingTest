#include<bits/stdc++.h>
using namespace std;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x = 0, y = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		cout << ny << "," << nx << '\n';
	}
}