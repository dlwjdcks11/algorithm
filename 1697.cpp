//���� 1697
#include <iostream>
#include <queue>
using namespace std;

int line[100001]; // ���ٲ��� �� ����, ���° �湮���� ������ ��
bool visited[100001]; // �湮���
int n, k;

int BFS() {
	queue<int> q;
	q.push(n);
	visited[n] = true; // �� ó�� �湮

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		if (tmp == k)
			return line[k]; // ���� ��, ������� ��� �Դ��� ��ȯ

		if (tmp - 1 >= 0 && tmp - 1 <= 100000 && !visited[tmp - 1]) { // ���� 0~10�� �����̰�, �湮�� �� ���ٸ�,
			visited[tmp - 1] = true;
			line[tmp - 1] = line[tmp] + 1;
			q.push(tmp - 1); // �湮������ְ�, �� ���ܿ��� + 1 �� ��ŭ�� ���� ���ܿ� ����, ���� 2�� if�� ���� ����
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