#include<bits/stdc++.h>
using namespace std;
int k, n, a[104], visited[104], cnt;
const int INF = 987654321;
vector<int> v;
int main() {
    cin >> k >> n; 
    for (int i = 0; i < n; i++) cin >> a[i]; // 2 3 2 3 1 5 7
    for (int i = 0; i < n; i++) {
        //ó���� 2 3 �� vector�� push
        if (!visited[a[i]]) {  // �湮�� �Ǿ��ִٸ� pass
            if (v.size() == k) {
                int last_idx = 0, pos;
                for (int _a : v) { 
                    int here_pick = INF; 
                    for (int j = i + 1; j < n; j++) { 
                        if( _a == a[j]) {   // i ���� ����� v�� �ִ� ���� �߰ߵȴٸ� last_idx,pos ����
                            here_pick = j; // �ش� �ε��� here_pick���� ���� 
                            break;
                        }
                    }
                    if (last_idx < here_pick) { // ���� ����� �ε������� �ָ� �ִٸ�? ����
                        last_idx = here_pick;  
                        pos = _a;               
                    }
                }
                visited[pos] = 0; // �湮���� ���������� ó�� == �ܼ�Ʈ�� �̴´�
                cnt++; // swap �� ����
                v.erase(find(v.begin(), v.end(), pos)); // 3 ����
            }
            v.push_back(a[i]); 
            visited[a[i]] = 1;
        }
    }
    cout << cnt << "\n";
    return 0;
} 