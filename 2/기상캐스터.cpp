#include<bits/stdc++.h>
using namespace std;
char c[104][104];
int a[104][104];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int index = 0;
		for (int j = 0; j < m; j++) {
			if (c[i][j] == 'c') {
				a[i][j] = 0;
				index = 1;
			}
			else if (index > 0) {
				a[i][j] = index;
				index++;
			}
			else {
				a[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}