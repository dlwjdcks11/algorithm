#include <iostream>
#include <string>
using namespace std;

string matrix[3001];
int fail[3001];
int n, m;

bool isOk(int y, int x) {
	return y > -1 && y < n && x > -1 && x < n;
}

void failure(string word) {
	fail[0] = 0;
	int i = 1;
	int j = 0;

	while (i < word.length()) {
		if (word[i] == word[j]) {
			fail[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) {
			j = fail[j - 1];
		}
		else {
			fail[i] = 0;
			i++;
		}
	}
}

bool KMP(string check, string word) {
	int i = 0;
	int j = 0;

	while (i < check.length()) {
		if (check[i] == word[j]) {
			if (j == word.length() - 1)
				return true;

			i++;
			j++;
		}
		else if (j > 0)
			j = fail[j - 1];
		else
			i++;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string check;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> matrix[i];
		check += matrix[i];
		check += ';';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check += matrix[j][i];
		}
		check += ';';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isOk(j, i + j))
				break;
			check += matrix[j][i + j];
		}
		check += ';';
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isOk(i + j, j))
				break;
			check += matrix[i + j][j];
		}
		check += ';';
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		failure(s);

		if (KMP(check, s))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int n, m;
//int fail[3001];
//string matrix[3001];
//
//bool isOk(int y, int x) {
//	return y > -1 && y < n && x > -1 && x < n;
//}
//
//void failure(string s) {
//	fail[0] = 0;
//	int i = 1;
//	int j = 0;
//
//	while (i < s.length()) {
//		if (s[i] == s[j]) {
//			fail[i] = j + 1;
//			i++;
//			j++;
//		}
//		else if (j > 0)
//			j = fail[j - 1];
//		else {
//			fail[i] = 0;
//			i++;
//		}
//	}
//}
//
//bool KMP(string check, string word) {
//	int i = 0;
//	int j = 0;
//
//	while (i < check.length()) {
//		if (check[i] == word[j]) {
//			if (j == word.length() - 1)
//				return true;
//
//			i++;
//			j++;
//		}
//		else if (j > 0)
//			j = fail[j - 1];
//		else
//			i++;
//	}
//
//	return false;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	string check = "";
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++) {
//		cin >> matrix[i];
//		check += matrix[i];
//		check += ";";
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			check += matrix[j][i];
//		}
//		check += ";";
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (!isOk(j, i + j))
//				break;
//
//			check += matrix[j][i + j];
//		}
//		check += ";";
//	}
//
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (!isOk(i + j, j))
//				break;
//
//			check += matrix[i + j][j];
//		}
//		check += ";";
//	}
//
//	for (int i = 0; i < m; i++) {
//		string word;
//		cin >> word;
//
//		failure(word);
//
//		if (KMP(check, word))
//			cout << 1 << '\n';
//		else
//			cout << 0 << '\n';
//	}
//		
//	return 0;
//}
//
//// 2���� �������� ��-�� ��-�� �»��-���ϴ����� �о� �ϳ��� ���ڿ����� �����.
//// padding ���ڸ� �߰��߰� �����ؼ� ������ �� ���ڿ��� �����. --> ���⼭ KMP
//// ���ڿ��� ����ġ �� �� Ž���� �����ߴ� �ؽ�Ʈ ��ġ�� �������Ͱ� �ƴ�, �̸� ����ߴ� ������ �̿��Ͽ� �� ĭ�� �ǳʶ� �� Ž��
//// ������ �� ��ġ���� ���λ�� ���̻簡 ��ġ�ϴ� �ִ� ����