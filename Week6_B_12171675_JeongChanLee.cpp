#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;

pair<int, int> p[4];
int n;
int direction[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

bool isOk(int y, int x) {
	return y > 0 && y <= n && x > 0 && x <= n;
}

int BFS(bool* matrix[], int* check[], int startY, int startX, int endY, int endX) {
	queue<pair<int, int>> q;
	int curY = startY;
	int curX = startX;
	q.push(pair<int, int>(curY, curX));

	while (!q.empty()) {
		curY = q.front().first;
		curX = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextY = curY + direction[i][0];
			int nextX = curX + direction[i][1];

			if (isOk(nextY, nextX)) {
				if (check[nextY][nextX] == 0 && matrix[nextY][nextX]) {
					check[nextY][nextX] = check[curY][curX] + 1;
					q.push(pair<int, int>(nextY, nextX));
				}
			}

			if (nextY == endY && nextX == endX)
				return check[nextY][nextX];
		}
	}

	return 0;
}

void solve() {
	cin >> n;

	bool** matrix = new bool*[n + 2];
	int** check = new int*[n + 2];
	for (int i = 0; i < n + 2; i++) {
		matrix[i] = new bool[n + 2];
		check[i] = new int[n + 2];
		memset(matrix[i], true, sizeof(bool) * (n + 2));
		memset(check[i], 0, sizeof(int) * (n + 2));
	}

	// 0: 인하, 1: 안전, 2: 검사, 3: 소총수
	for (int i = 0; i < 4; i++) {
		int y, x;
		cin >> y >> x;

		p[i].first = y;
		p[i].second = x;

		if (i == 2) {
			for (int i = 0; i < 8; i++) {
				int nextY = y + direction[i][0];
				int nextX = x + direction[i][1];

				if (isOk(nextY, nextX))
					matrix[nextY][nextX] = false;
			}
		}
		else if (i == 3) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < n; j++) {
					int nextY = y + direction[i][0] * j;
					int nextX = x + direction[i][1] * j;

					if (!isOk(nextY, nextX))
						break;
					if (nextY == p[2].first && nextX == p[2].second)
						break;

					matrix[nextY][nextX] = false;
				}
			}
		}
	}

	cout << BFS(matrix, check, p[0].first, p[0].second, p[1].first, p[1].second) << '\n';
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

 // 그냥 쭉 돌리면서 못가는곳 가는곳 다 구분해주기