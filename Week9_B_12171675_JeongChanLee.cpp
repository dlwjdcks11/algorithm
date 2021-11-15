#include <iostream>
#include <cstring>
using namespace std;

int n, q;
int direction[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

bool isOk(int y, int x) {
	return y > 0 && y <= n && x > 0 && x <= n;
}

// 흑 1 백 2
void solve() {
			
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

// 후보군 찾는 함수를 따로 만들면 되겠네
// 순서 넘어가는 경우가 있어서 무조건 후보군 만들어야 한다.