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
		f(n, r, depth + 1); // depth로 끝까지 가서 Print -> return 하면서 for i 증가 시키며 return
		swap(v1, i, depth); //  depth로 i가 깊어진 상황이라 역순 swap
	}                           // 최종에는 0,0 상황에서 for 문을 돌며 depth가 얕은곳 swap
}
int main() {
	for (int i = 1; i <= 5; i++) {
		v1.push_back(i);
	}
	f(5, 5, 0);
}