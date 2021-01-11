//���� 9019
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
	visited[input] = true; // ù ���ڿ� ��� ����ְ�, �湮 ǥ��

	while (!q.empty()) {
		int tmp = q.front().first;
		string path = q.front().second;
		q.pop();

		if (tmp == output) { // Ż���
			cout << path << '\n';
			return;
		}

		//D (���� ������ �ι� % 10000)
		int nextNum = (tmp * 2) % 10000;
		if (!visited[nextNum]) {
			visited[nextNum] = true;
			q.push(pair<int, string>(nextNum, path + "D"));
		}

		//S (���� ���� - 1, 0 �̸��̶�� 9999�� ����)
		nextNum = (tmp - 1) < 0 ? 9999 : tmp - 1;
		if (!visited[nextNum]) {
			visited[nextNum] = true;
			q.push(pair<int, string>(nextNum, path + "S"));
		}

		//L (���� ȸ��, 1234->2341)
		nextNum = (tmp % 1000) * 10 + tmp / 1000;
		if (!visited[nextNum]) {
			visited[nextNum] = true;
			q.push(pair<int, string>(nextNum, path + "L"));
		}

		//R (������ ȸ��, 1234->4123)
		nextNum = (tmp % 10) * 1000 + tmp / 10;
		if (!visited[nextNum]) {
			visited[nextNum] = true;
			q.push(pair<int, string>(nextNum, path + "R"));
		}
	}
}

void solve() {
	cin >> input >> output;

	memset(visited, false, 10000); // �迭 �ʱ�ȭ
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
