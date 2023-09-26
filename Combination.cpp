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
	} // 마지막 4가 처음으로 들어오는 부분 부터 v.size()를 만족하지 않아 출력되지 않음 because 4 5 끝 
	return;
}

int main() {
	comb(-1, v1);
}