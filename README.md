## 정사각 배열 90도 회전
```c++
temp[i][j]=a[n-j-1][i];
```

## rotate()
```c++
vector<int> v ={1,2,3,4,5}; 
rotate(v.rbegin(),v.rbegin()+1,v.end()); // 요소 1개별 오른쪽 회전
// {5,1,2,3,4}

vector<int> v={1,2,3,4,5}; 
rotate(v.begin(),v.begin()+1,v.end()); // 요소 1개별 왼쪽 회전
// {2,3,4,5,1}
```
## Integer 배열 10억 이상 컴파일 오류, for문 10억 이상 시간초과
```c++
int a=1e9; // 10억
```
<br>

## 최대 자릿수
Int -> 10자리 
 
long long -> 20자리

<br>

## 배열 왕복(도착되는 칸)
```c++
//인덱스는 0부터 시작

int nx = (x+ 움직이려는 칸의 개수) % 2*(열의 개수 - 1);
int ny = (y+ 움직이려는 칸의 개수) % 2*(행의 개수 - 1);
```

## 소수점 자리수 출력
```c++
double a = 1.234567;
cout << fixed << setprecision(3) <<a<<"\n";
```

## 소수 배열
```c++
int che[104];

vector<int>v;
for(int i=2;i<=100;i++){
  if(che[i])continue;
  for(int j=i*2;j<=100;j+=i){
    che[j]=1;
  }
}
for(int i=2;i<=100;i++){
  if(che[i]==0) v.push_back(i);
}
```
