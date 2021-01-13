//백준 9084
#include <iostream>
#include <string.h>
using namespace std;

int dp[10001];

void solve() {
	memset(dp, 0, sizeof(dp)); //dp 배열 초기화
	int coin[21]; //동전 입력받을 배열
	int n, total;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> coin[i];
	cin >> total;

	dp[0] = 1; //dp 쓰기위해 첫번째 인덱스 1로 설정
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= total; j++)
			dp[j] += dp[j - coin[i]]; //dp 진행, 10원을 2, 3, 5로 만들때를 생각하여 식 세웠다. 2-> 2 4 6 8 10, 2 and 3-> 3 4 5 6 7 8 9 10... 
	}

	cout << dp[total] << '\n'; //맨 마지막에 오는 경우의 수 출력
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}