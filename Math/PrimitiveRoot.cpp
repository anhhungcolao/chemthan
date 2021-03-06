#include <bits/stdc++.h>
using namespace std;

vector<int> dvs;
int fpow(int n, int k, int p) {
	int r = 1;
	for (; k; k >>= 1) {
		if (k & 1) r = (long long) r * n % p;
		n = (long long) n * n % p;
	}
	return r;
}
int primitiveroot(int p) {
	dvs.clear();
	for (int i = 2; i * i < p; i++) {
		if ((p - 1) % i) continue;
		dvs.push_back(i);
		if (i * i != p - 1) dvs.push_back((p - 1) / i);
	}
	for (int i = 2; i < p; i++) {
		int flag = 1;
		for (int j = 0; j < dvs.size(); j++) {
			if (fpow(i, dvs[j], p) == 1) {
				flag = 0;
				break;
			}
		}
		if (flag) return i;
	}
}

int main() {
	cout << primitiveroot(1000000007) << "\n";
	return 0;
}
