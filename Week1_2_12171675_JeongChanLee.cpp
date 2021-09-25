#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	vector<int> v;
	int max;
	int min;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;

		if (op == 1) {
			int block;
			cin >> block;
			v.push_back(block);

			if (v.size() == 1) {
				min = block;
				max = block;
				cout << min << ' ' << max << '\n';
				continue;
			}
			
			if (block < min) {
				min = block;
			}
			else if (block > max) {
				max = block;
			}
			
			cout << min << ' ' << max << '\n';
		}
		if (op == 2 && v.size() != 0) {		
			if (v[v.size() - 1] == min) {
				v.pop_back();
				min = *min_element(v.begin(), v.end());
			}
			else if (v[v.size() - 1] == max) {
				v.pop_back();
				max = *max_element(v.begin(), v.end());
			}
			else {
				v.pop_back();
			}
		}
	}
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