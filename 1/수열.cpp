#include<bits/stdc++.h>
using namespace std;
int N, K;
int temp;
int arr[100004];
int pre[100004];
int m;
int ret = -10000004;
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		pre[i] = pre[i - 1] +temp;
	}
	for (int i = K; i<= N; i++) {
		int max = pre[i] - pre[i-K];
		if (ret < max) {
			m = max;
		}
		ret = m;
	}
	cout << ret << endl;
}