//백준 1759
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int L, C;
vector<string> answer;

void combination(vector<char> v, vector<char> comb, int index, int depth) { // 조합 algorithm
		if (depth == comb.size()) { // L개만큼 다 뽑았으면
			string tmp = ""; 
			sort(comb.begin(), comb.end()); // 알파벳 순 정렬
			for (int i = 0; i < comb.size(); i++) 
				tmp += comb[i];
			answer.push_back(tmp); //답 벡터에 push
	
			return;
		}
	
		for (int i = index; i < v.size(); i++) { // 입력 갯수만큼 돌면서
			comb[depth] = v[i]; // 하나씩 뽑기
			combination(v, comb, i + 1, depth + 1); //뽑았으면 다음 index로 이동
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