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

// 그리디
// 자원의 가치가 인하, 비룡에서 각각 x, y인 자원에 대해 인하가 가져가면 비룡은 y를 잃게 되므로 상대적으로 인하가 x + y의 가치를 확보
// 각 자원의 두 왕국에서의 가치의 합을 기준으로 정렬
// 두 왕국은 가치의 합이 높은 자원부터 우선확보

// X + y를 순으로 sort를 해서 가장 높은 가격부터 순서대로 가져가면 끝

// objective function(최대) <-> cost(loss) function(최소) == 딥러닝(Cross Entropy Function)

// 자원의 가치의 합이 같더라도 계산했을때 차를 계산하면 모두 같게 나온다.