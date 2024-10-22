#include<bits/stdc++.h>
using namespace std;
int n,a[91];
int fibo(int cnt) {
	if (cnt < 0)return 0;
	if (cnt == 1)return 1;
	if (a[cnt]) return a[cnt];
	return a[cnt]= fibo(cnt - 1) + fibo(cnt - 2);
}
int main() {
	cin >> n;
	cout<<fibo(n);
}