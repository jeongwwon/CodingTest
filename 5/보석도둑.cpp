#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ret, temp1, temp;
int main() {
	cin >> n >> k;
	vector<pair<ll, ll>>v(n);
	vector<ll>vv(k);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < k; i++) {
		cin >> vv[i];
	}
	sort(v.begin(), v.end()); //무게 오름차순 , 같을시 가격이 높은순
	sort(vv.begin(), vv.end()); //배낭무게 오름차순
	priority_queue<ll>pq;
	int j = 0;
	//배낭을 오름차순 정렬했으니 j를 0부터 시작 안해도됌 == 작은 배낭에 담을수 있는 보석은 큰배낭에도 담을수 있고 pq에 남아있기 때문
	for (int i = 0; i < k; i++) {
		while (j < n && v[j].first <= vv[i]) pq.push(v[j++].second); //v[j].first 무게가 가방 vv를 넘지 않는다면 pq에 넣고 j증가
		//pq는 가격이 비싼 것(v[j].second)가 top에 오게 되고 pop
		if (pq.size()) {
			ret += pq.top(); pq.pop();
		}
	}
	cout << ret << "\n";
}