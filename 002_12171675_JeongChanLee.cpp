#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct element { // ������ ������ ������ �л� ��ȣ ������ ����ü ����
	list<int> adj;
	int index = -1;
};

vector<element> v; // �⺻���� �Է°��� ������� element ����ü�� vector��
vector<element> backtracking; // backtracking�� ���� v�� �ݴ�������� ����� vector
vector<element> backtracking2; // ���� sort ���꿡 ���� ���ĵ��� ���� backtracking vector
bool visited[50001]; // ���� DFS ���� �� �湮�� ��� ������ ������ �迭
bool backVisited[50001]; // backtracking ���� �� �湮�� ��� ������ ������ �迭
bool finished[50001]; // ���� DFS ���� �� DFS�� ����� ��带 �����ϱ� ���� �迭
bool backFinished[50001]; // backtracking ���� �� backtracking�� ����� ��带 �����ϱ� ���� �迭
int sccLeader[50001]; // �� �л��� SCC leader�� �����ϱ� ���� �迭
stack<int> s; // Finishing stack�� stack

bool cmp(element a, element b) { // backtracking vector ���Ŀ� �Լ�
	if (a.adj.size() != b.adj.size()) // a�� list size(a�� �ȷο�)��, b�� list size(b�� �ȷο�)�� �ٸ��ٸ�,
		return a.adj.size() > b.adj.size(); // �ȷο��� ���� ������ ����
	return a.index < b.index; // ���ٸ�, �л� ��ȣ�� ���� ������ ����
}

bool vcmp(const int& a, const int& b) { // v vector�� ���� list ���Ŀ� �Լ�
	if (backtracking2[a - 1].adj.size() != backtracking2[b - 1].adj.size()) // backtracking2�� �����Ͽ�, �� �л��� �ȷο� ���� �ٸ��ٸ�,
		return backtracking2[a - 1].adj.size() > backtracking2[b - 1].adj.size(); // �ȷο��� ���� ������ ����
	return backtracking2[a - 1].index < backtracking2[b - 1].index; // ���ٸ�, �л� ��ȣ�� ���� ������ ����
}

void DFS(int cur) { // DFS �Լ�, cur�� ���� �л� ��ȣ���� 1�� �۴�.
	if (finished[cur + 1]) // cur + 1�� �̹� ����� �����,
		return; // �Լ� ����

	visited[cur + 1] = true; // cur + 1 �湮�ߴٰ� �˸�

	if (v[cur].adj.empty()) { // cur���� �� �̻� �� �� �ִ� ��尡 ���ٸ�,
		cout << cur + 1 << ' '; // stack�� ���� ���̹Ƿ�, ���
		s.push(cur + 1); // finishing stack�� ����
		finished[cur + 1] = true; // cur + 1�� finishing stack�� ���ٰ� �˸�
		return;
	}

	for (auto value : v[cur].adj) { // cur��°�� node���� �� �� �ִ� �������� ��� Ȯ���Ѵ�.
		if (!visited[value]) // ���� �湮���� �ʾҴٸ�, 
			DFS(value - 1); // ���� �л� ��ȣ���� 1�� �� ������ DFS ��� ����
	}

	// cur + 1�� ���� finishing stack�� ���µ�, for���� ��� �����ߴٸ�, �� �̻� �� ���� ���� ���̹Ƿ� finish �Ǿ�� �Ѵ�.
	if (!finished[cur + 1]) { 
		cout << cur + 1 << ' '; // stack�� ���� ���̹Ƿ�, ���
		finished[cur + 1] = true; // cur + 1�� finishing stack�� ���ٰ� �˸�
		s.push(cur + 1); // finishing stack�� ����
		return;
	}
}

void getLeader(int cur, int leader) { // SCC�� leader�� ���ϴ� �Լ�, cur�� leader�� �Ű������� �޾Ƽ�, leader�� SCC�� leader�� �����Ѵ�.
	if (backFinished[cur]) // cur�� �̹� ����� �����,
		return; // �Լ� ����

	backVisited[cur] = true; // cur �湮�ߴٰ� �˸�

	if (backtracking2[cur - 1].adj.empty()) { // backtracking2 vector�� cur - 1 ���� index���� �� �̻� �� �� �ִ� ������ ���ٸ�,
		sccLeader[cur] = leader; // �л���ȣ cur���� leader ����
		backFinished[cur] = true; // backtracking ����Ǿ��ٰ� �˸�
		return; // �Լ� ����
	}

	for (auto value : backtracking2[cur - 1].adj) { // backtracking2 vector�� cur - 1��°�� node���� �� �� �ִ� ������ ��� Ȯ���Ѵ�.
		if (!backVisited[value]) // ���� �湮���� �ʾҴٸ�,
			getLeader(value, leader); // getLeader ��� ����
	}

	// for���� ����Ǿ��ٸ�, �� �̻� �� ������ ���� ���̹Ƿ�, finish �Ǿ�� �Ѵ�.
	if (!backFinished[cur]) {
		sccLeader[cur] = leader; // leader ����
		backFinished[cur] = true; // cur��° node�� finish �Ǿ��ٰ� �˸�
		return;
	}
}

int main() {
	int n, m; // vertex, edge �� �Է�
	cin >> n >> m;

	for (int i = 0; i < n; i++) { // ���͵� �ʱ�ȭ, ������ index�� i�� �����Ͽ� �Էµ��� �ʴ� edge�� ����� �� �ְ� �Ѵ�.
		element e;
		e.index = i;
		v.push_back(e);
		backtracking.push_back(e);
		backtracking2.push_back(e);
	}

	for (int i = 0; i < m; i++) { // edge ���� �Է�
		int src, dst;
		cin >> src >> dst;
		v[src - 1].adj.push_back(dst); // �迭�� index�� �Ǿ�� �ϹǷ� src���� 1�� ���� dst ����
		v[src - 1].index = src - 1;

		backtracking[dst - 1].adj.push_back(src); // v�� �ݴ�������� ����
		backtracking[dst - 1].index = dst - 1;

		backtracking2[dst - 1].adj.push_back(src); // backtracking�� �����ϰ� ����
		backtracking2[dst - 1].index = dst - 1;
	}

	sort(backtracking.begin(), backtracking.end(), cmp); // cmp �Լ��� �������� backtracking vector ����

	for (int i = 0; i < n; i++) 
		v[i].adj.sort(vcmp); // vcmp �Լ��� �������� v�� ���� list �� ����

	for (int i = 0; i < n; i++)
		DFS(backtracking[i].index); // ���ĵ� backtracking vector�� �л� ��ȣ ������ DFS ����
	cout << '\n';

	for (int i = 0; i < n; i++) { // ������� finishing stack�� top�� �������� getLeader ����
		getLeader(s.top(), s.top());
		s.pop(); // �� ���� ���� ��, pop()���� �� �� ��� ����
	}

	for (int i = 1; i <= n; i++)
		cout << sccLeader[i] << ' '; // �� scc�� Leader ���
		
	return 0;
}