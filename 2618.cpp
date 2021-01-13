//���� 2618
#include <iostream>
using namespace std;

long long dp[1000001]; //dp �迭 ����

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1; //dp ����ϱ� ���� �ʱ�ȭ

	for (int i = 3; i <= n; i++)
		dp[i] = ((dp[i - 2] + dp[i - 1]) * (i - 1)) % 1000000000; //((�� ��) + (���� ��)) * (���� �� �� - 1) mod 10�� 

	cout << dp[n] << '\n'; //���

	return 0;
}