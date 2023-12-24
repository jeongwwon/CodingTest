#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>>a;
bool cmp(pair<int, int>a, pair<int, int>b) {

	return a.first > b.first;
}
int main() {
	for (int i = 0; i < 10; i++) {
		a.push_back({ i,10 - i });
	}
	sort(a.begin(), a.end(), cmp);
	for (auto i : a) {
		cout << i.first<<":"<<i.second << "\n";
	}
	cout << "\n";

}