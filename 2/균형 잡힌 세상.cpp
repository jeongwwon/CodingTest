#include<bits/stdc++.h>

using namespace std;
string s;
bool check(string s) {
	stack<char> stk;
	for (char c : s) {
		if (isalpha(c) || c==' ' || c=='.') continue;
		if (c == '(' || c == '[') stk.push(c);
		else {
			if (stk.empty()) return false;
			if (c == ')' && stk.top() == '(') stk.pop();
			else if (c == ')' && stk.top()=='[') return false;
			else if (c == ']' && stk.top() == '[')stk.pop();
			else if (c == ']' && stk.top()=='(') return false;
		}
	}
	return stk.empty();
}
int main() {
	while (1) {
		getline(cin, s);
		if (s[0] =='.' && s.size() == 1 )break;
		if (check(s)) cout << "yes\n";
		else cout << "no\n";
	}
}