#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first + p1.second > p2.first + p2.second;
}

void solve() {
	vector<pair<int, int>> v;
	int ans = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v.push_back(make_pair(num1, num2));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			ans += v[i].first;
		else
			ans -= v[i].second;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}

// �׸���
// �ڿ��� ��ġ�� ����, ��濡�� ���� x, y�� �ڿ��� ���� ���ϰ� �������� ����� y�� �Ұ� �ǹǷ� ��������� ���ϰ� x + y�� ��ġ�� Ȯ��
// �� �ڿ��� �� �ձ������� ��ġ�� ���� �������� ����
// �� �ձ��� ��ġ�� ���� ���� �ڿ����� �켱Ȯ��

// X + y�� ������ sort�� �ؼ� ���� ���� ���ݺ��� ������� �������� ��

// objective function(�ִ�) <-> cost(loss) function(�ּ�) == ������(Cross Entropy Function)

// �ڿ��� ��ġ�� ���� ������ ��������� ���� ����ϸ� ��� ���� ���´�.