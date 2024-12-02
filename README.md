## 정사각 배열 90도 회전
```c++
temp[i][j]=a[n-j-1][i];
```

## rotate()
```c++
// vector<int> v는 ={1,2,3,4,5}; 
rotate(v.rbegin(),v.rbegin()+1,v.end()); // 요소 1개별 오른쪽 회전
// {5,1,2,3,4}

// vector<int> v는 ={1,2,3,4,5}; 
rotate(v.begin(),v.begin()+1,v.end()); // 요소 1개별 왼쪽 회전
// {2,3,4,5,1}
```
## Integer 배열 10억 이상 컴파일 오류

## 배열 왕복(도착되는 칸)
```c++
//인덱스는 0부터 시작

int nx = (x+ 움직이려는 칸의 개수) % 2*(열의 개수 - 1);
int ny = (y+ 움직이려는 칸의 개수) % 2*(행의 개수 - 1);
```
