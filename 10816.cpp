//น้มุ 10816 - upper bound, lower bound
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
struct Card {
	int num;
	int have;
};

int upperBinarySearch(int* v, int data) {
	int start = 0;
	int end = n - 1;
	int find;

	while (start < end) {
		find = (start + end) / 2;

		if (v[find] > data)
			end = find;
		else
			start = find + 1;
	}

	return end;
}

int lowerBinarySearch(int* v, int data) {
	int start = 0;
	int end = n - 1;
	int find;

	while (start < end) {
		find = (start + end) / 2;

		if (v[find] >= data)
			end = find;
		else
			start = find + 1;
	}
	return end;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int* v = new int[n];

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v, v + n);

	cin >> m;
	Card* card = new Card[m];
	for (int i = 0; i < m; i++) {
		cin >> card[i].num;
		card[i].have = 0;
	}

	for (int i = 0; i < m; i++) {
		int lower = lowerBinarySearch(v, card[i].num);
		int upper = upperBinarySearch(v, card[i].num);

		if (upper == n - 1 && v[n - 1] == card[i].num)
			upper++;

		card[i].have = upper - lower;
	}
	for (int i = 0; i < m; i++)
		cout << card[i].have << " ";
	cout << '\n';

	return 0;
}