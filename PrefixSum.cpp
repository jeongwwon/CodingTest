#include<iostream>
int psum[100004], a[100004],b,c, n, m;
using namespace std;
int main() {
	cout << "�迭�� ���� ���� ���� �Է��ϼ���:";
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}

	for (int i = 0; i < m; i++) {
		cout << "���° ī��� ���° ī�带 �������? :";
		cin >> b >> c;
		cout << "��������:" << psum[b] - psum[c - 1] << endl;
	}
}
