#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v1;
void swap(vector<int>& v1,int a,int b) {
	int temp = v1[a];
	v1[a] = v1[b];
	v1[b] = temp;

}
void print(vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}
void f(int n, int r, int depth) {
	//cout << n << ":" << r << ":" << depth << endl;
	if (r == depth) {
		print(v1);
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(v1,i,depth);
		f(n, r, depth + 1); // depth�� ������ ���� Print -> return �ϸ鼭 for i ���� ��Ű�� return
		swap(v1, i, depth); //  depth�� i�� ����� ��Ȳ�̶� ���� swap
	}                           // �������� 0,0 ��Ȳ���� for ���� ���� depth�� ������ swap
}
int main() {
	for (int i = 1; i <= 5; i++) {
		v1.push_back(i);
	}
	f(5, 5, 0);
}