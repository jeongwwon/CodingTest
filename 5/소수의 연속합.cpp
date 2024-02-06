#include<bits/stdc++.h>
using namespace std;
const int mx_n = 4000001;
bool che[mx_n];
int n, a[2000001], p, lo, hi, ret, sum;
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= mx_n; i++) {
		if (che[i])continue;
		for (int j = i * 2; j <= mx_n; j += i) {
			che[j] = 1;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (!che[i])a[p++] = i; // i가 소수라면 a 배열에 0부터 소수를 채워 넣는다.
	}
	while (1) {
		if (sum >= n) sum -= a[lo++];
		else if (hi == p)break;
		else sum += a[hi++];
		if (sum == n)ret++;
	}
	printf("%d\n",ret);
}