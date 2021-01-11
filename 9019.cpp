//백준 9019
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int input, output;
bool visited[10000];

void BFS() {
	queue<pair<int, string> > q;
	q.push(pair<int, string>(input, ""));
	visited[input] = true; // 첫 숫자와 경로 집어넣고, 방문 표기

	while (!q.empty()) {
		int tmp = q.front().first;
		string path = q.front().second;
		q.pop();

		if (tmp == output) { // 탈출부
			cout << path << '\n';
			return;
		}

		//D (현재 숫자의 두배 % 10000)
		int nextNum = (tmp * 2) % 10000;
		if (!visited[nextNum]) {
			visited[nextNum] = true;
			q.push(pair<int, string>(nextNum, path + "D"));
		}

		//S (현재 숫자 - 1, 0 미만이라면 9999로 간다)
		nextNum = (tmp - 1) < 0 ? 9999 : tmp - 1;
		if (!visited[nextNum]) {
			visited[nextNum] = true;
			q.push(pair<int, string>(nextNum, path + "S"));
		}

		//L (왼쪽 회전, 1234->2341)
		nextNum = (tmp % 1000) * 10 + tmp / 1000;
		if (!visited[nextNum]) {
			visited[nextNum] = true;
			q.push(pair<int, string>(nextNum, path + "L"));
		}

		//R (오른쪽 회전, 1234->4123)
		nextNum = (tmp % 10) * 1000 + tmp / 10;
		if (!visited[nextNum]) {
			visited[nextNum] = true;
			q.push(pair<int, string>(nextNum, path + "R"));
		}
	}
}

void solve() {
	cin >> input >> output;

	memset(visited, false, 10000); // 배열 초기화
	BFS();
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}
