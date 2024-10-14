#include<bits/stdc++.h>
using namespace std;
int binarySearch(const vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		else if (target < arr[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

int main() {
	vector<int>arr = { 1,3,6,10,9,21,22,30 };
	sort(arr.begin(), arr.end());
	int target = 6;
	int result = binarySearch(arr, target);
	if (result != -1) {
		cout << "Target found at index:" << result << "\n";
	}
	else {
		cout << "Target not found in the array\n";
	}
}