#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Customer {
	int time;
	int price;
};

struct Counter {
	int endTime;
	int number;

	bool operator<(const Counter c) const {
		if (this->endTime != c.endTime)
			return this->endTime > c.endTime;
		else
			return this->number > c.number;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<Counter> pq;
	int n, m, maxTime = -1;
	cin >> n >> m;
	Customer* customer = new Customer[m];
	int* cost = new int[n];

	for (int i = 0; i < m; i++) {
		int time, price;
		cin >> time >> price;
		customer[i].time = time;
		customer[i].price = price;

		if (i < n) {
			Counter c;
			c.endTime = customer[i].time;
			c.number = i;
			pq.push(c);
			cost[i] = customer[i].price;
			maxTime = max(maxTime, customer[i].time);
		}
	}

	for (int i = n; i < m; i++) {
		Counter c = pq.top();
		pq.pop();
		c.endTime += customer[i].time;
		cost[c.number] += customer[i].price;
		maxTime = max(maxTime, c.endTime);
		pq.push(c);
	}

	cout << maxTime << '\n';
	for (int i = 0; i < n; i++)
		cout << cost[i] << '\n';

	return 0;
}
// priority queue
// ���� �̿��� ������ �ð��� ���� ���� ���� �켱 ������ �ο��Ѵ�.
// ���� �̿��� ������ �ð��� ���ٸ�, ���� ��ȣ�� ���� ���� ���� �켱 ������ �ο��Ѵ�.
// ó���� ���� ���ڸ�ŭ pq�� �����Ѵ�.
// ���� ���� �ð� = ���밡 ���� ���� ���ݱ��� �� �ð�(��ٸ� �ð�) + ���� �� �ð�
// �̷��� ���� priority queue�� ��� ������, ������ ����� �ð��� ����ð�