//���� 11048
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
			cin >> mage[i][j]; //�̷� �Է�
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			dp[i][j] = max({ dp[i - 1][j - 1] + mage[i][j], dp[i - 1][j] + mage[i][j], dp[i][j - 1] + mage[i][j] }); 
	}//�� index�� ��, �Ʒ�, �밢�� ���� ���� ���� �̷ΰ��� ���� ���� ���Ͽ� ���� ū �� ����

	cout << dp[n][m] << '\n'; //���

	return 0;
}
