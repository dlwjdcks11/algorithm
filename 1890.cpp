//백준 1890
#include <iostream>
#include <string.h>
using namespace std;

int n;
int matrix[101][101];
long long dp[101][101];

bool isOk(int y, int x) {
	return y > 0 && y <= n && x > 0 && x <= n; // 범위를 벗어나지 않는지 확인
}

long long DP(int y, int x) {
	if (y == n && x == n)
		return 1;
	if (!isOk(y, x) || matrix[y][x] == 0) //범위를 벗어나거나, 갈 수 있는 거리가 0이면 return, 여기서 matrix[y][x] 체크 안해서 자꾸 메모리 초과 났었음
		return 0;
	if (dp[y][x] != -1)
		return dp[y][x]; //메모이제이션

	return dp[y][x] = DP(y + matrix[y][x], x) + DP(y, x + matrix[y][x]); //dp[1][1]을 구하기 위해 계속 앞으로가서 진행 후 역으로 더하면서 돌아옴
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> matrix[i][j];
	}
	memset(dp, -1, sizeof(dp)); //초기화
	cout << DP(1, 1) << '\n'; //출력

	return 0;
}