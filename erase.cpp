#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main() {
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}
	v.erase(find(v.begin(),v.end(),3));
	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";
}