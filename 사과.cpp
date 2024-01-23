#include<bits/stdc++.h>
using namespace std;
const int n = 4;
string a[n] = { "사과","딸기","포도","배" };

void go(int num) {
	string ret = "";
	for (int i = 0; i < 4; i++) {
		if (num & (1 << i)) ret += a[i] + " ";
	}
	cout << ret << "\n";
}
int main() {
	for (int i = 0; i < (1 << n); i++) {
		string ret = "";
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				ret += (a[j] + " ");
			}
		}
		cout << ret << "\n";
	}
	cout << "-----매개변수 포함------" << "\n";
	//매개변수 포함 조합 구하기
	for (int i = 0; i < n; i++) {
		go(1 | (1 << i)); // 1 5(101) 9(1001) 사과는 포함
	}
}