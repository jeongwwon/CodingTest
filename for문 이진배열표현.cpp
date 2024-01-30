#include<bits/stdc++.h>
using namespace std;
// n:2 m:3 
int main() {
	for (int s = 0; s < (1 << 2 * 3); s++) {
		bitset<10>binary(s);
		std::cout << binary << "\n";
	}
}