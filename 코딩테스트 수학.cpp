#include<bits/stdc++.h>
using namespace std;
//�ּ� �����
int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}
//�ּ� �����
int lcm(int a, int b) {
	int ch=gcd(a, b);
	cout << "�ִ� �����:" << ch << "\n";
	return (a * b) /ch;
}
//�����佺�׳׽��� ü: �Ҽ��� �ƴ� ���鿡 ���� �Ҹ��� �迭 ����
const int max_n = 40;
bool che[max_n + 1];
vector<int>era(int mx_n) {
	vector<int>v;
	for (int i = 2; i <= mx_n; i++) {
		if (che[i])continue;
		for (int j = 2 * i; j <= mx_n; j += i) {
			che[j] = 1;
		}
	}
	for (int i = 2; i <= mx_n; i++) {
		if (che[i] == 0) {
			v.push_back(i);
		}
	}
	return v;
}
//�Ҽ� üũ �Լ�, �迭�� ũ�Ⱑ 1000�� �̻��϶�
bool check(int a) {
	if (a <= 1)return 0;
	if (a == 2)return 1;
	if (a % 2==0)return 0;
	for (int i = 2; i*i <= a; i++) {
		if (a % i==0) return 0;
	}
	return 1;
}
//���� ������ ��: a:���� b:���� c:���� ��
int sum(int a, int b, int c) {
	// ��������: c-1 * b + a
	int l = (c - 1) * b + a;
	return c*(a + l) / 2;
}
int main() {
	cout << "--�ִ� �����--\n";
	int a = 10, b = 12;
	cout << lcm(a, b) << "\n";
	cout << "--�����佺�׳׽��� ü--\n";
	vector<int>vv = era(max_n);
	for (int i : vv) {
		cout << i << " ";
	}
	cout << "\n--���� ������ ��--\n";
	cout << sum(3, 5, 5) << "\n";
	cout << "\n--��� ������ ��--\n";
	int a1 = 1, r = 2, n = 4;//���� 1,���� 2,�� 4��
	vector<int>v;
	cout << a1 * ((int)pow(r, n) - 1) / (r - 1)<<"\n";  //pow�� double ���� ��ȯ�ϱ� ������ int ��ȯ �ʿ��ϴ�.
	for (int i = 0; i < n; i++) {
		v.push_back(a1);
		a1 *= r;
	}
	for (int t : v)cout << t << " ";
}