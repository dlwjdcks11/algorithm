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

// 친구들의 수 만큼의 queue 생성
// 친구들이 작성한 단어들을 각각 대응하는 큐에 순서대로 삽입
// 대상이 되는 문장의 단어들이 각각 임의의 큐의 front에 존재하는지 확인 하고 삭제
// 대상 문장의 모든 단어에 대해 3을 반복