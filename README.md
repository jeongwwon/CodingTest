## 정사각 배열 90도 회전
```c++
a[i][j]=a[n-j-1][i];
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
