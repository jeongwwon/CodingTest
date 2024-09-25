#include<bits/stdc++.h>
using namespace std;
const int INF = -987654321;
int n,ret=INF;
struct A {
	int a[21][21];
	void _move() {
		int temp[21][21];
		for (int i = 0; i < n; i++) {
			int c = -1, d = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0)continue;
				if (d && temp[i][c] == a[i][j]) temp[i][c] *= 2, d = 0;
				else temp[i][++c] = a[i][j],d=1;
			}
			for (c++; c < n; c++) {
				temp[i][c] = 0;
			}
		}
		memcpy(a, temp, sizeof(a));
	}
	void _rotate90() {
		int temp[21][21];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = a[n - j - 1][i];
			}
		}
		memcpy(a, temp, sizeof(a));
	}
	void get_max() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret = max(ret, a[i][j]);
			}
		}
	}
};
void go(int here,A b) {
	if (here == 5) {
		b.get_max();
		return;
	}
	for (int i = 0; i < 4; i++) {
		A c = b;
		c._move();
		go(here + 1, c);
		b._rotate90();
	}
	return;
}
int main() {
	cin >> n;
	A c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c.a[i][j];
		}
	}
	go(0,c);
	cout << ret << "\n";
}