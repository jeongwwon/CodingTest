#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret, temp;
stack<pair<ll, ll>>s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		int cnt = 1;
		while (s.size() && s.top().first <= temp) {
			ret += s.top().second;  //ret은 stack에 있는 cnt값들을 더해주면서 짝짓기 수를 누적
			//cout << "ret값:" << ret << "\n";
			if (s.top().first == temp) {
				cnt = s.top().second + 1;
			}
			else {
				cnt = 1;
			}
			s.pop(); //temp가 큰것이 들어왔기 때문에 전의 stack은 pop해준다.(앞으로 관계 없기 때문)
		}
		if (s.size())ret++;
		//cout << "ret값:" << ret << "\n";
		s.push({ temp,cnt });
		//cout << "temp:" << temp << "," << "cnt:" << cnt << "\n";
	}
	cout << ret << "\n";
}
