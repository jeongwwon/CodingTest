#include<bits/stdc++.h>
using namespace std;

int main() {
	for (int s = 0; s < (1 << 2 * 3); s++) {
		bitset<6>binary(s);
		std::cout << binary << "\n";
	}
}