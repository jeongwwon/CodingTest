#include<bits/stdc++.h>
using namespace std;

int n, lis[1001], len, num;
//함수(lower_bound)는 연속으로 증가하는 부분 배열의 개수만 알면되기 때문에
//해당 위치에서 자기보다 크거나 같은 값을 대체하기만 하면 최대 증가 부분 수열의 개수와 일치한다.
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		auto lowerPos = lower_bound(lis, lis + len, num);
		if (*lowerPos == 0)len++;
		*lowerPos = num;
		for (int j = 0; j < n; j++) {
			printf("%d ", lis[j]);
		}
		printf("\n");
	}
	printf("%d", len);
}