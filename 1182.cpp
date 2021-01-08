//백준 1182
#include <iostream>
#include <vector>
using namespace std;

int N, S;
int answer = 0;

void combination(vector<int> v, vector<int> comb, int index, int depth) { // 조합 알고리즘
	if (depth == comb.size()) { // main의 i개만큼 다 뽑았으면,
		int tmp = 0;
		for (int i = 0; i < comb.size(); i++) // 뽑힌 수 전부 합하기
			tmp += comb[i];

		if (tmp == S) // 합이 S와 같다면,
			answer++; // 경우의 수 1개 추가

		return;
	}

	for (int i = index; i < v.size(); i++) {
		comb[depth] = v[i];
		combination(v, comb, i + 1, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	vector<int> v;
	cin >> N >> S;

	for (int i = 0; i < N; i++) { //입력
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 1; i <= N; i++) { // 1~N개만큼 뽑음
		vector<int> comb(i);
		combination(v, comb, 0, 0);
	}
	cout << answer << '\n';

	return 0;
}