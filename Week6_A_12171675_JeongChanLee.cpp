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
// 계산대 이용이 끝나는 시간이 가장 적을 수록 우선 순위를 부여한다.
// 계산대 이용이 끝나는 시간이 같다면, 계산대 번호가 가장 낮을 수록 우선 순위를 부여한다.
// 처음엔 계산대 숫자만큼 pq에 대입한다.
// 예상 종료 시간 = 계산대가 열고 나서 지금까지 쓴 시간(기다린 시간) + 내가 쓸 시간
// 이렇게 계산대 priority queue에 계속 넣으면, 마지막 사람의 시간이 종료시간