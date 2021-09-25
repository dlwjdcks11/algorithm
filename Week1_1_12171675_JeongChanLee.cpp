#include <iostream>
#include <string>
using namespace std;

char zigzag[1001][1001];

void solve() {
	string input;
	string output = "";
	int row;

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			zigzag[i][j] = NULL;
		}
	}
		
	cin >> input >> row;

	for (int i = 0; i < input.length(); i++) {
		if ((i / row) % 2 == 0)
			zigzag[i % row][i / row] = input[i];
		else
			zigzag[row - (i % row) - 1][i / row] = input[i];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; zigzag[i][j] != NULL; j++) {
			output += zigzag[i][j];
		}
	}

	cout << output << '\n';
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