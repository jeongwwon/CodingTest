#include<bits/stdc++.h>
using namespace std;
int main() {
	cout << "---- - 반시계 방향--------\n";
	vector<int>v = { 1,2,3,4,5,6 };
	//2칸 이동 
	rotate(v.begin(), v.begin() + 2, v.end());
	for (int i : v) { cout << i << " "; }
	cout << "\n";
	//특정 구간 회전
	vector<int>v2 = { 1,2,3,4,5,6 };
	rotate(v2.begin() + 1, v2.begin() + 2, v2.end()-1);
	for (int i : v2) cout << i << " ";
	cout << "\n";
	cout << "------시계 방향----------\n";
	vector<int>v3 = { 1,2,3,4,5,6 };
	rotate(v3.rbegin(), v3.rbegin() + 1, v3.rend());
	for (int i : v3)cout << i << " ";
	cout << "\n";
}