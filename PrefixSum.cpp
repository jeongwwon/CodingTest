#include<iostream>
int psum[100004], a[100004],b,c, n, m;
using namespace std;
int main() {
	cout << "배열의 수와 게임 수를 입력하세요:";
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}

	for (int i = 0; i < m; i++) {
		cout << "몇번째 카드와 몇번째 카드를 뽑을까요? :";
		cin >> b >> c;
		cout << "누적합은:" << psum[b] - psum[c - 1] << endl;
	}
}
