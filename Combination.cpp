#include<iostream>
#include<vector>
using namespace std;
vector<int> v1;
int n = 5;
int k = 3;
void print(vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void comb(int start,vector<int>&v) {
	if (v.size() == k) {
		print(v);
		return;
	}
	for (int i = start + 1; i <n; i++) {
		v.push_back(i);
		comb(i, v);
		v.pop_back();
	} // ������ 4�� ó������ ������ �κ� ���� v.size()�� �������� �ʾ� ��µ��� ���� because 4 5 �� 
	return;
}

int main() {
	comb(-1, v1);
}