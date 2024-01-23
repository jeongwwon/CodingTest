#include<bits/stdc++.h>
using namespace std;
int main() {
	//비트 끄기
	int a = 18;//10010
	int idx = 1;
	a &= ~(1 << idx);
	cout << a << "\n";
	//비트 켜기
	int b = 16;//10000
	idx = 1;
	b |= (1 << idx);
	cout << b << "\n";
	//XOR 부호 반대
	int c = 16;
	c ^= (1 << idx);
	cout << c << "\n";
	//최하위 켜져있는 비트 찾기
	int d = 17;//10001
	idx = (d & -d); // ~d = -(d+1) , -d=~d+1
	//10001 -> 01110 +1 =01111 & 10001 = 00001
	cout << idx << "\n";
}