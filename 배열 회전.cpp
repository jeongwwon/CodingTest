#include<bits/stdc++.h>
using namespace std;
int main() {
	cout << "---- - �ݽð� ����--------\n";
	vector<int>v = { 1,2,3,4,5,6 };
	//2ĭ �̵� 
	rotate(v.begin(), v.begin() + 2, v.end());
	for (int i : v) { cout << i << " "; }
	cout << "\n";
	//Ư�� ���� ȸ��
	vector<int>v2 = { 1,2,3,4,5,6 };
	rotate(v2.begin() + 1, v2.begin() + 2, v2.end()-1);
	for (int i : v2) cout << i << " ";
	cout << "\n";
	cout << "------�ð� ����----------\n";
	vector<int>v3 = { 1,2,3,4,5,6 };
	rotate(v3.rbegin(), v3.rbegin() + 1, v3.rend());
	for (int i : v3)cout << i << " ";
	cout << "\n";
}