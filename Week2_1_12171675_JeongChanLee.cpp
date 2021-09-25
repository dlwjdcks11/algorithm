#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void solve() {
	int stu, len;
	vector<string> professor;
	vector<queue<string>> v;
	cin >> stu >> len;

	for (int i = 0; i < len; i++) {
		string tmp;
		cin >> tmp;
		professor.push_back(tmp);
	}

	for (int i = 0; i < stu; i++) {
		queue<string> q;
		int n;
		cin >> n;

		for (int j = 0; j < n; j++) {
			string tmp;
			cin >> tmp;
			q.push(tmp);
		}
		v.push_back(q);
	}

	for (int i = 0; i < len; i++) {
		bool flag = false;

		for (int j = 0; j < stu; j++) {
			if (professor[i] == v[j].front()) {
				v[j].pop();
				flag = true;
				break;
			}
		}

		if (!flag) {
			cout << 0 << '\n';
			return;
		}
	}

	cout << 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}

// ģ������ �� ��ŭ�� queue ����
// ģ������ �ۼ��� �ܾ���� ���� �����ϴ� ť�� ������� ����
// ����� �Ǵ� ������ �ܾ���� ���� ������ ť�� front�� �����ϴ��� Ȯ�� �ϰ� ����
// ��� ������ ��� �ܾ ���� 3�� �ݺ�