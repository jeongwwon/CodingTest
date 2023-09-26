#include<bits/stdc++.h>
using namespace std;
int a[9];
int n = 9, r = 7;
void valid() {
	int sum=0;
	for (int i = 0; i < 7; i++) {
		sum += a[i];
	}
	if (sum == 100) {
		sort(a, a + 7);
		for (int i = 0; i < 7; i++) {
			cout << a[i] << " ";
		}
		exit(0);
	}
}
void Permutation(int n,int r,int depth) {
	if (r==depth) {
		valid();
		return;
	}
	for (int i = depth; i <n; i++) {
		swap(a[i],a[depth]);
		Permutation(n, r, depth + 1);
		swap(a[i],a[depth]);
	}
	return;
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	Permutation(n,r,0);
	return 0;
}