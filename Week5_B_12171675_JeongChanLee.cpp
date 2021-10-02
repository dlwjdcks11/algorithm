#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int* house = new int[n];

	for (int i = 0; i < n; i++)
		cin >> house[i];

	int left = 1;
	int right = house[n - 1] - house[0];
	int d = 0;
	int answer = 0;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		int start = house[0];
		int count = 1;

		for (int i = 1; i < n; i++) {
			d = house[i] - start;

			if (mid <= d) {
				count++;
				start = house[i];
			}
		}

		if (count >= m) {
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << answer << '\n';

	return 0;
}