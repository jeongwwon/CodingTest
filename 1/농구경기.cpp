#include<bits/stdc++.h>
using namespace std;
int N;
string str;
int arr[30];
int cnt;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		arr[str[0] - 'a'] += 1;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			cout << char(i + 'a');
			cnt++;
		}
	}
	if (cnt == 0) {
		cout << "PREDAJA";
	}
}