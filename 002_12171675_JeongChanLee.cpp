#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct element { // 인접한 정점의 정보와 학생 번호 저장할 구조체 선언
	list<int> adj;
	int index = -1;
};

vector<element> v; // 기본적인 입력값을 저장받을 element 구조체의 vectorㄴ
vector<element> backtracking; // backtracking을 위해 v의 반대방향으로 저장될 vector
vector<element> backtracking2; // 추후 sort 연산에 사용될 정렬되지 않은 backtracking vector
bool visited[50001]; // 최초 DFS 실행 시 방문한 노드 정보를 저장할 배열
bool backVisited[50001]; // backtracking 실행 시 방문할 노드 정보를 저장할 배열
bool finished[50001]; // 최초 DFS 실행 시 DFS가 종료된 노드를 저장하기 위한 배열
bool backFinished[50001]; // backtracking 실행 시 backtracking이 종료된 노드를 저장하기 위한 배열
int sccLeader[50001]; // 각 학생의 SCC leader를 저장하기 위한 배열
stack<int> s; // Finishing stack용 stack

bool cmp(element a, element b) { // backtracking vector 정렬용 함수
	if (a.adj.size() != b.adj.size()) // a의 list size(a의 팔로워)와, b의 list size(b의 팔로워)가 다르다면,
		return a.adj.size() > b.adj.size(); // 팔로워가 많은 순으로 정렬
	return a.index < b.index; // 같다면, 학생 번호가 작은 순으로 정렬
}

bool vcmp(const int& a, const int& b) { // v vector의 내부 list 정렬용 함수
	if (backtracking2[a - 1].adj.size() != backtracking2[b - 1].adj.size()) // backtracking2를 참조하여, 각 학생의 팔로워 수가 다르다면,
		return backtracking2[a - 1].adj.size() > backtracking2[b - 1].adj.size(); // 팔로워가 많은 순으로 정렬
	return backtracking2[a - 1].index < backtracking2[b - 1].index; // 같다면, 학생 번호가 작은 순으로 정렬
}

void DFS(int cur) { // DFS 함수, cur은 실제 학생 번호에서 1이 작다.
	if (finished[cur + 1]) // cur + 1이 이미 종료된 노드라면,
		return; // 함수 종료

	visited[cur + 1] = true; // cur + 1 방문했다고 알림

	if (v[cur].adj.empty()) { // cur에서 더 이상 갈 수 있는 노드가 없다면,
		cout << cur + 1 << ' '; // stack에 넣을 것이므로, 출력
		s.push(cur + 1); // finishing stack에 삽입
		finished[cur + 1] = true; // cur + 1이 finishing stack에 들어갔다고 알림
		return;
	}

	for (auto value : v[cur].adj) { // cur번째의 node에서 갈 수 있는 정점들을 모두 확인한다.
		if (!visited[value]) // 아직 방문하지 않았다면, 
			DFS(value - 1); // 실제 학생 번호에서 1을 뺀 값으로 DFS 재귀 실행
	}

	// cur + 1이 아직 finishing stack에 없는데, for문을 모두 수행했다면, 더 이상 갈 곳이 없는 것이므로 finish 되어야 한다.
	if (!finished[cur + 1]) { 
		cout << cur + 1 << ' '; // stack에 넣을 것이므로, 출력
		finished[cur + 1] = true; // cur + 1이 finishing stack에 들어갔다고 알림
		s.push(cur + 1); // finishing stack에 삽입
		return;
	}
}

void getLeader(int cur, int leader) { // SCC의 leader를 구하는 함수, cur과 leader를 매개변수로 받아서, leader를 SCC의 leader로 지정한다.
	if (backFinished[cur]) // cur이 이미 종료된 노드라면,
		return; // 함수 종료

	backVisited[cur] = true; // cur 방문했다고 알림

	if (backtracking2[cur - 1].adj.empty()) { // backtracking2 vector의 cur - 1 번쨰 index에서 더 이상 갈 수 있는 정점이 없다면,
		sccLeader[cur] = leader; // 학생번호 cur번의 leader 설정
		backFinished[cur] = true; // backtracking 종료되었다고 알림
		return; // 함수 종료
	}

	for (auto value : backtracking2[cur - 1].adj) { // backtracking2 vector의 cur - 1번째의 node에서 갈 수 있는 정점들 모두 확인한다.
		if (!backVisited[value]) // 아직 방문하지 않았다면,
			getLeader(value, leader); // getLeader 재귀 실행
	}

	// for문이 종료되었다면, 더 이상 갈 정점이 없는 것이므로, finish 되어야 한다.
	if (!backFinished[cur]) {
		sccLeader[cur] = leader; // leader 설정
		backFinished[cur] = true; // cur번째 node가 finish 되었다고 알림
		return;
	}
}

int main() {
	int n, m; // vertex, edge 수 입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) { // 벡터들 초기화, 최초의 index는 i로 지정하여 입력되지 않는 edge도 계산할 수 있게 한다.
		element e;
		e.index = i;
		v.push_back(e);
		backtracking.push_back(e);
		backtracking2.push_back(e);
	}

	for (int i = 0; i < m; i++) { // edge 정보 입력
		int src, dst;
		cin >> src >> dst;
		v[src - 1].adj.push_back(dst); // 배열의 index가 되어야 하므로 src에서 1을 빼서 dst 삽입
		v[src - 1].index = src - 1;

		backtracking[dst - 1].adj.push_back(src); // v와 반대방향으로 삽입
		backtracking[dst - 1].index = dst - 1;

		backtracking2[dst - 1].adj.push_back(src); // backtracking과 동일하게 삽입
		backtracking2[dst - 1].index = dst - 1;
	}

	sort(backtracking.begin(), backtracking.end(), cmp); // cmp 함수를 기준으로 backtracking vector 정렬

	for (int i = 0; i < n; i++) 
		v[i].adj.sort(vcmp); // vcmp 함수를 기준으로 v의 내부 list 값 정렬

	for (int i = 0; i < n; i++)
		DFS(backtracking[i].index); // 정렬된 backtracking vector의 학생 번호 순으로 DFS 실행
	cout << '\n';

	for (int i = 0; i < n; i++) { // 만들어진 finishing stack의 top을 기준으로 getLeader 실행
		getLeader(s.top(), s.top());
		s.pop(); // 한 번의 시행 후, pop()으로 맨 위 요소 제거
	}

	for (int i = 1; i <= n; i++)
		cout << sccLeader[i] << ' '; // 각 scc의 Leader 출력
		
	return 0;
}