#include<bits/stdc++.h>
using namespace std;
char c[1004];
string s;
map<int, string> mp;
int main() {
	int count = 0;
	while (1) {
		cin >> s;
		if (s == "end") break;
		mp[count++] = s;
	}
	for (int i = 0; i < mp.size(); i++) {
		if (mp[i].find('a') == string::npos || mp[i].find('e') == string::npos || mp[i].find('i') == string::npos || mp[i].find('o') == string::npos || mp[i].find('u') == string::npos) {
			cout << "<" << mp[i] << ">" << " is not acceptable."<<"\n";
			continue;
		}
		for (int i = mp.size() - 1; 0 < i; i--) {
			if (mp[i] == mp[i - 1] && mp[i].find('e') == string::npos && mp[i].find('o') == string::npos) {
				cout << "<" << mp[i] << ">" << " is not acceptable."<<"\n";
				continue;
			}
		}
		cout << "<" << mp[i] << ">" << " is acceptable."<<"\n";
	}
}