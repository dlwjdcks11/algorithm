//백준 1697
#include <iostream>
#include <queue>
using namespace std;

int line[100001]; // 숨바꼭질 줄 생성, 몇번째 방문인지 저장할 것
bool visited[100001]; // 방문기록
int n, k;

int BFS() {
	queue<int> q;
	q.push(n);
	visited[n] = true; // 맨 처음 방문

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		if (tmp == k)
			return line[k]; // 도착 시, 현재까지 몇번 왔는지 반환

		if (tmp - 1 >= 0 && tmp - 1 <= 100000 && !visited[tmp - 1]) { // 값이 0~10만 사이이고, 방문한 적 없다면,
			visited[tmp - 1] = true;
			line[tmp - 1] = line[tmp] + 1;
			q.push(tmp - 1); // 방문기록해주고, 전 스텝에서 + 1 한 만큼을 현재 스텝에 저장, 이하 2개 if문 로직 동일
		}
		if (tmp + 1 <= 100000 && !visited[tmp + 1]) {
			visited[tmp + 1] = true;
			line[tmp + 1] = line[tmp] + 1;
			q.push(tmp + 1);
		}
		if (tmp * 2 <= 100000 && !visited[tmp * 2]) {
			visited[tmp * 2] = true;
			line[tmp * 2] = line[tmp] + 1;
			q.push(tmp * 2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	cout << BFS() << endl;

	return 0;
}