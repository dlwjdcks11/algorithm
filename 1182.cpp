//���� 1182
#include <iostream>
#include <vector>
using namespace std;

int N, S;
int answer = 0;

void combination(vector<int> v, vector<int> comb, int index, int depth) { // ���� �˰���
	if (depth == comb.size()) { // main�� i����ŭ �� �̾�����,
		int tmp = 0;
		for (int i = 0; i < comb.size(); i++) // ���� �� ���� ���ϱ�
			tmp += comb[i];

		if (tmp == S) // ���� S�� ���ٸ�,
			answer++; // ����� �� 1�� �߰�

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

	for (int i = 0; i < N; i++) { //�Է�
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 1; i <= N; i++) { // 1~N����ŭ ����
		vector<int> comb(i);
		combination(v, comb, 0, 0);
	}
	cout << answer << '\n';

	return 0;
}