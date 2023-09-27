#include<bits/stdc++.h>
using namespace std;
int A, B, C;
int a, b;
int sum=0;
int arr[104];
int main() {
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			arr[j]++;
		}
	}
	for (int j = 1; j < 100; j++) {
		if (arr[j]) {
			if (arr[j] == 1) {
				sum += A;
			}
			else if (arr[j] == 2) {
				sum += B * 2;
			}
			else if (arr[j] == 3) {
				sum += C * 3;
			}
		}
	}
	cout << sum;
	return 0;
}