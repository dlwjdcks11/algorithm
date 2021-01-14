//���� 1890
#include <iostream>
#include <string.h>
using namespace std;

int n;
int matrix[101][101];
long long dp[101][101];

bool isOk(int y, int x) {
	return y > 0 && y <= n && x > 0 && x <= n; // ������ ����� �ʴ��� Ȯ��
}

long long DP(int y, int x) {
	if (y == n && x == n)
		return 1;
	if (!isOk(y, x) || matrix[y][x] == 0) //������ ����ų�, �� �� �ִ� �Ÿ��� 0�̸� return, ���⼭ matrix[y][x] üũ ���ؼ� �ڲ� �޸� �ʰ� ������
		return 0;
	if (dp[y][x] != -1)
		return dp[y][x]; //�޸������̼�

	return dp[y][x] = DP(y + matrix[y][x], x) + DP(y, x + matrix[y][x]); //dp[1][1]�� ���ϱ� ���� ��� �����ΰ��� ���� �� ������ ���ϸ鼭 ���ƿ�
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> matrix[i][j];
	}
	memset(dp, -1, sizeof(dp)); //�ʱ�ȭ
	cout << DP(1, 1) << '\n'; //���

	return 0;
}