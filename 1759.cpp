//���� 1759
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int L, C;
vector<string> answer;

void combination(vector<char> v, vector<char> comb, int index, int depth) { // ���� algorithm
		if (depth == comb.size()) { // L����ŭ �� �̾�����
			string tmp = ""; 
			sort(comb.begin(), comb.end()); // ���ĺ� �� ����
			for (int i = 0; i < comb.size(); i++) 
				tmp += comb[i];
			answer.push_back(tmp); //�� ���Ϳ� push
	
			return;
		}
	
		for (int i = index; i < v.size(); i++) { // �Է� ������ŭ ���鼭
			comb[depth] = v[i]; // �ϳ��� �̱�
			combination(v, comb, i + 1, depth + 1); //�̾����� ���� index�� �̵�
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> L >> C;
	vector<char> v;
	vector<char> comb(L);

	for (int i = 0; i < C; i++) {
		char tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	combination(v, comb, 0, 0);
	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		int consonant = 0;
		int vowel = 0;
		for (int j = 0; j < L; j++) {
			if (answer[i][j] == 'a' || answer[i][j] == 'e' || answer[i][j] == 'i' || answer[i][j] == 'o' || answer[i][j] == 'u')
				vowel++;
			else
				consonant++;
		}
		if (vowel > 0 && consonant > 1)
			cout << answer[i] << '\n';
	}

	return 0;
}