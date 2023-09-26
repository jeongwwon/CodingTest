#include<iostream>

int N,cnt;
using namespace std;
void solve(int N) {
	int a = 0,i = N;
	while (i > 0) {
		a += i;
		i /= 3;
		cnt++;
	}
	cout << a << "\n";
	cout << cnt << "\n";
}
int main() {
	cin >> N;
	solve(N);

}