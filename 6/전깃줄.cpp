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
		if (!(*it))len++; // a[i].second�� lis�� ��� �迭�� �� ���� ũ�ٸ� ��ġ�� �������� �������� �ʴ´�.(����)
							// a[i].second�� lis�� �迭���� ���ų� �̻��ΰ��� ù��° �ε����� ��ȯ�ߴٸ� �迭�� ���ԵǱ��� �ڱ⺸�� ū���� �����Ͽ� �����Ѵٴ� �ǹ�(������)
		*it = a[i].second;
	}
	printf("%d\n", n - len);
}