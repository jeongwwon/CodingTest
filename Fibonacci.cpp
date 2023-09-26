#include<iostream>
using namespace std;
int fibo(int n) {
	if (n < 3) {
		return 1;
	}
	else {
		return fibo(n - 1) + fibo(n - 2);
	}
}
void fibofor(int n) {
	int a = 1; 
	int b = 1;
	int sum = 0;
	cout << a<<" "<<b<<" ";
	for (int i = 1; i <= n; i++) {
		sum = a + b;
		a = b;
		b=sum;
		cout << sum<< " ";
	}
	// 1 1 2 3 5 8
}

int main() {
	//cout<<fibo(10);
	cout<<fibo(4);
	// 1 1 2 3 5 8 
	// 12 or 20 
}