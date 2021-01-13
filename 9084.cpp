//���� 9084
#include <iostream>
#include <string.h>
using namespace std;

int dp[10001];

void solve() {
	memset(dp, 0, sizeof(dp)); //dp �迭 �ʱ�ȭ
	int coin[21]; //���� �Է¹��� �迭
	int n, total;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> coin[i];
	cin >> total;

	dp[0] = 1; //dp �������� ù��° �ε��� 1�� ����
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= total; j++)
			dp[j] += dp[j - coin[i]]; //dp ����, 10���� 2, 3, 5�� ���鶧�� �����Ͽ� �� ������. 2-> 2 4 6 8 10, 2 and 3-> 3 4 5 6 7 8 9 10... 
	}

	cout << dp[total] << '\n'; //�� �������� ���� ����� �� ���
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}