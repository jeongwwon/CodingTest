#include<bits/stdc++.h>
using namespace std;

int n, lis[1001], len, num;
//�Լ�(lower_bound)�� �������� �����ϴ� �κ� �迭�� ������ �˸�Ǳ� ������
//�ش� ��ġ���� �ڱ⺸�� ũ�ų� ���� ���� ��ü�ϱ⸸ �ϸ� �ִ� ���� �κ� ������ ������ ��ġ�Ѵ�.
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