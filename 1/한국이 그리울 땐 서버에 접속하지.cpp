#include<bits/stdc++.h>
using namespace std;
string str,s;
int N;
int main() {
	cin >> N;
	cin >> str;
	int pos = str.find('*');
	string pre = str.substr(0, pos);
	string suf = str.substr(pos+1);
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (pre.size() + suf.size() > s.size()) {
			cout << "NE" << endl;
		}
		else {
			if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size()-suf.size())) {
				cout << "DA" << endl;
			}
			else {
				cout << "NE" << endl;
			}
		}
	}
	
	return 0;
}