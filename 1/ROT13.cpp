#include<bits/stdc++.h>
using namespace std;
string str;
string out;
int main() {
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i]<='Z') {
			if (90 < str[i] + 13) {
				out += 'A' + (13 - (90 - str[i]))-1;
			}
			else {
				out += char(str[i] + 13);
			}
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			if (122 < str[i] + 13) {
				out += 'a' + (13-(122 - str[i]))-1;
			}
			else {
				out += char(str[i] + 13);
			}
		}
		else {
			out += str[i];
		}
	}
	cout << out;
}