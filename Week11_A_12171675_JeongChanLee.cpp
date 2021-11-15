#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int*, int>> v;
	queue<pair<int*, int>> q;
	int alp[26];
	int n;
	int answer = 0;

	for (int i = 0; i < 26; i++)
		cin >> alp[i];

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		int score;
		int tmpAlp[26] = { };

		cin >> s >> score;

		for (int i = 0; i < s.size(); i++) {
			tmpAlp[s[i] - '0' - 49]++;
		}

		v.push_back({ tmpAlp, score });
		q.push({ tmpAlp, score });
	}

	cout << answer << '\n';

	return 0;
}