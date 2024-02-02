#include<bits/stdc++.h>
using namespace std;
string S, T, ret;
stack<char>stk;
int main() {
	cin >> S >> T;
	for (char a : S) {
		stk.push(a);
		string ss;
		if (stk.size() >= T.size() && stk.top() == T[T.size() - 1]) {
			for (char i : T) {
				ss += stk.top();
				stk.pop();
			}
		}
		reverse(ss.begin(), ss.end());
		if (ss != T) {
			for (char i : ss) {
				stk.push(i);
			}
		}
	}
	if (stk.size() == 0) {
		cout << "FRULA\n";
	}
	else {
		string ss;
		while (stk.size()) {
			ss+=stk.top();
			stk.pop();
		}
		reverse(ss.begin(), ss.end());
		cout << ss << "\n";
	}
}