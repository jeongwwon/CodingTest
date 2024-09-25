#include<bits/stdc++.h>
using namespace std;
int k, n, a[104], visited[104], cnt;
const int INF = 987654321;
vector<int> v;
int main() {
    cin >> k >> n; 
    for (int i = 0; i < n; i++) cin >> a[i]; // 2 3 2 3 1 5 7
    for (int i = 0; i < n; i++) {
        //처음에 2 3 을 vector에 push
        if (!visited[a[i]]) {  // 방문이 되어있다면 pass
            if (v.size() == k) {
                int last_idx = 0, pos;
                for (int _a : v) { 
                    int here_pick = INF; 
                    for (int j = i + 1; j < n; j++) { 
                        if( _a == a[j]) {   // i 다음 요소중 v에 있는 값이 발견된다면 last_idx,pos 갱신
                            here_pick = j; // 해당 인덱스 here_pick으로 저장 
                            break;
                        }
                    }
                    if (last_idx < here_pick) { // 만약 저장된 인덱스보다 멀리 있다면? 갱신
                        last_idx = here_pick;  
                        pos = _a;               
                    }
                }
                visited[pos] = 0; // 방문하지 않은것으로 처리 == 콘센트를 뽑는다
                cnt++; // swap 수 증가
                v.erase(find(v.begin(), v.end(), pos)); // 3 제거
            }
            v.push_back(a[i]); 
            visited[a[i]] = 1;
        }
    }
    cout << cnt << "\n";
    return 0;
} 