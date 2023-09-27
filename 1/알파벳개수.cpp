#include<bits/stdc++.h>
int b[26];
using namespace std;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < 26; i++) {
		b[i] = 0;
	}
	for (char h : str) {
		b[h - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << b[i] << " ";
	}	
	return 0;
}
