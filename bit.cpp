#include<bits/stdc++.h>
using namespace std;
int main() {
	//��Ʈ ����
	int a = 18;//10010
	int idx = 1;
	a &= ~(1 << idx);
	cout << a << "\n";
	//��Ʈ �ѱ�
	int b = 16;//10000
	idx = 1;
	b |= (1 << idx);
	cout << b << "\n";
	//XOR ��ȣ �ݴ�
	int c = 16;
	c ^= (1 << idx);
	cout << c << "\n";
	//������ �����ִ� ��Ʈ ã��
	int d = 17;//10001
	idx = (d & -d); // ~d = -(d+1) , -d=~d+1
	//10001 -> 01110 +1 =01111 & 10001 = 00001
	cout << idx << "\n";
}