#include<bits/stdc++.h>
using namespace std;
string a;
int main() {
	cin >> a;
	string b = a;
	reverse(b.begin(), b.end());
	if (a == b) {
		cout << 1 << endl;
	}
	else if(a != b) {
		cout << 0 << endl;
	}
}