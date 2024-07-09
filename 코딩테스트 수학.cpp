#include<bits/stdc++.h>
using namespace std;
//최소 공약수
int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}
//최대 공배수
int lcm(int a, int b) {
	int ch=gcd(a, b);
	cout << "최대 공약수:" << ch << "\n";
	return (a * b) /ch;
}
//에라토스테네스의 체: 소수가 아닌 값들에 대한 불리언 배열 생성
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
//소수 체크 함수, 배열의 크기가 1000만 이상일때
bool check(int a) {
	if (a <= 1)return 0;
	if (a == 2)return 1;
	if (a % 2==0)return 0;
	for (int i = 2; i*i <= a; i++) {
		if (a % i==0) return 0;
	}
	return 1;
}
//등차 수열의 합: a:초항 b:등차 c:항의 수
int sum(int a, int b, int c) {
	// 마지막항: c-1 * b + a
	int l = (c - 1) * b + a;
	return c*(a + l) / 2;
}
int main() {
	cout << "--최대 공약수--\n";
	int a = 10, b = 12;
	cout << lcm(a, b) << "\n";
	cout << "--에라토스테네스의 체--\n";
	vector<int>vv = era(max_n);
	for (int i : vv) {
		cout << i << " ";
	}
	cout << "\n--등차 수열의 합--\n";
	cout << sum(3, 5, 5) << "\n";
	cout << "\n--등비 수열의 합--\n";
	int a1 = 1, r = 2, n = 4;//초항 1,공비 2,항 4개
	vector<int>v;
	cout << a1 * ((int)pow(r, n) - 1) / (r - 1)<<"\n";  //pow는 double 형을 반환하기 때문에 int 변환 필요하다.
	for (int i = 0; i < n; i++) {
		v.push_back(a1);
		a1 *= r;
	}
	for (int t : v)cout << t << " ";
}
