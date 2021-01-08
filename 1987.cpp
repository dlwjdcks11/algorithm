//���� 1987
#include <iostream>
#include <algorithm>
using namespace std;

int R, C; //����, ����
int answer = -1;
char matrix[20][20]; // ��Ʈ����
int alphabet[26];
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; // ����

bool isOk(int y, int x) { // ���� ���� �ִ��� üũ
	return y > -1 && y < R&& x > -1 && x < C;
}

void DFS(int y, int x, int cnt) { // DFS Ž��
	answer = max(answer, cnt); // �ִ� ����

	for (int i = 0; i < 4; i++) { // 4���� ��ȸ
		int nextY = y + direction[i][0];
		int nextX = x + direction[i][1];

		if (!isOk(nextY, nextX)) // �����ܶ�� ������ȯ
			continue;

		int tmp = (int)matrix[nextY][nextX] - 65;
		if (alphabet[tmp]) // ���ĺ� �� �� ������ ������ȯ
			continue;

		alphabet[tmp]++; // �� ���ĺ� �Ծ��ٰ� ǥ��
		DFS(nextY, nextX, cnt + 1); // ī��Ʈ �ϳ� �ø��� ���� ĭ�� ���� DFS ���
		alphabet[tmp]--; // �ٸ� ��� Ž���� ����ؾ� �ϴ� �� ���ĺ��� �Ծ��ٴ� ǥ�� ����
	}
}