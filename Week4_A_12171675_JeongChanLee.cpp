#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void solve() {
	int A, B, x, y;
	cin >> A >> B >> x >> y;
	int gcd = abs(A - B);
	int dec = A / gcd;
	int inc = dec + 1;
	int decCnt = A - dec * gcd;
	int incCnt = inc * gcd - A;

	if (A < B) {
		if (A - decCnt < 1) {
			cout << gcd << " " << incCnt * x << '\n';
			return;
		}
		cout << gcd << " " << min(incCnt * x, decCnt * y) << '\n';
	}
	else {
		if (B - decCnt < 1) {
			cout << gcd << " " << incCnt * x << '\n';
			return;
		}
		cout << gcd << " " << min(incCnt * x, decCnt * y) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}