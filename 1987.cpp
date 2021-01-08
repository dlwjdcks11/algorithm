//백준 1987
#include <iostream>
#include <algorithm>
using namespace std;

int R, C; //세로, 가로
int answer = -1;
char matrix[20][20]; // 매트릭스
int alphabet[26];
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; // 방향

bool isOk(int y, int x) { // 범위 내에 있는지 체크
	return y > -1 && y < R&& x > -1 && x < C;
}

void DFS(int y, int x, int cnt) { // DFS 탐색
	answer = max(answer, cnt); // 최댓값 갱신

	for (int i = 0; i < 4; i++) { // 4방향 순회
		int nextY = y + direction[i][0];
		int nextX = x + direction[i][1];

		if (!isOk(nextY, nextX)) // 범위외라면 방향전환
			continue;

		int tmp = (int)matrix[nextY][nextX] - 65;
		if (alphabet[tmp]) // 알파벳 온 적 있으면 방향전환
			continue;

		alphabet[tmp]++; // 이 알파벳 왔었다고 표시
		DFS(nextY, nextX, cnt + 1); // 카운트 하나 늘리고 다음 칸에 대해 DFS 재귀
		alphabet[tmp]--; // 다른 경로 탐색에 사용해야 하니 이 알파벳에 왔었다는 표시 제거
	}
}