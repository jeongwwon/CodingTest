#include<bits/stdc++.h>
using namespace std;
pair<int, int>a[10001];
int n,len,lis[10001];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		auto it=lower_bound(lis, lis + len, a[i].second);
		if (!(*it))len++; // a[i].second가 lis의 모든 배열의 값 보다 크다면 겹치는 전기줄이 존재하지 않는다.(정상)
							// a[i].second가 lis의 배열에서 같거나 이상인값의 첫번째 인덱스를 반환했다면 배열에 삽입되기전 자기보다 큰값이 존재하여 교차한다는 의미(비정상)
		*it = a[i].second;
	}
	printf("%d\n", n - len);
}