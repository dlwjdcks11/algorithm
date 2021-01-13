//백준 2618
#include <iostream>
using namespace std;

long long dp[1000001]; //dp 배열 선언

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1; //dp 사용하기 위해 초기화

	for (int i = 3; i <= n; i++)
		dp[i] = ((dp[i - 2] + dp[i - 1]) * (i - 1)) % 1000000000; //((전 항) + (전전 항)) * (현재 항 수 - 1) mod 10억 

	cout << dp[n] << '\n'; //출력

	return 0;
}