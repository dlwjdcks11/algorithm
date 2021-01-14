//백준 11048
#include <iostream>
#include <algorithm>
using namespace std;

int mage[1001][1001];
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> mage[i][j]; //미로 입력
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			dp[i][j] = max({ dp[i - 1][j - 1] + mage[i][j], dp[i - 1][j] + mage[i][j], dp[i][j - 1] + mage[i][j] }); 
	}//각 index에 위, 아래, 대각선 왼쪽 위와 다음 미로값과 더한 값에 비교하여 가장 큰 값 대입

	cout << dp[n][m] << '\n'; //출력

	return 0;
}
