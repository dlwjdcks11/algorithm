#include <iostream>
#include <cstring>
using namespace std;

int n, q;
int direction[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

bool isOk(int y, int x) {
	return y > 0 && y <= n && x > 0 && x <= n;
}

// �� 1 �� 2
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

// �ĺ��� ã�� �Լ��� ���� ����� �ǰڳ�
// ���� �Ѿ�� ��찡 �־ ������ �ĺ��� ������ �Ѵ�.