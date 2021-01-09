//백준 10816 - upper bound, lower bound
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
struct Card { // 찾을 카드의 구조체 선언
	int num;
	int have;
};

int upperBinarySearch(int* v, int data) { // 찾고자 하는 값들의 바로 뒤의 인덱스에 접근하는 upperBinarySerach 알고리즘
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

int lowerBinarySearch(int* v, int data) { // 찾고자 하는 값들의 첫 번째 인덱스에 접근하는 lowerBinarySearch 알고리즘
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

	sort(v, v + n); //최초 입력값 삽입 후 정렬

	cin >> m;
	Card* card = new Card[m];
	for (int i = 0; i < m; i++) {
		cin >> card[i].num;
		card[i].have = 0;
	} // 카드 정보 담을 배열 생성

	for (int i = 0; i < m; i++) {
		int lower = lowerBinarySearch(v, card[i].num);
		int upper = upperBinarySearch(v, card[i].num);

		if (upper == n - 1 && v[n - 1] == card[i].num) // 에러로 인한 오류처리, 만약 upper가 마지막 인덱스에 접근했거나, 배열의 마지막 원소에 접근하는 것이라면, upper 하나 추가함
			upper++;

		card[i].have = upper - lower; // (찾고자 하는 값들의 1 큰 인덱스) - (찾고자 하는 값들의 첫 번째 인덱스) = (찾고자 하는 값의 갯수)
	}
	for (int i = 0; i < m; i++)
		cout << card[i].have << " ";
	cout << '\n'; // 출력

	return 0;
}