// 2-2 BM algorithm
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int last[26]; // lastOccurrence 함수의 결과값 저장할 배열. a~z를 0~25번 인덱스에 저장한다.
int X = -1; // X의 등장 위치는 따로 변수로 저장한다.
vector<int> v; // 패턴의 등장 index 저장할 벡터

void lastOccurrence(string find) { // lastOccurrence 함수
	for (int i = 0; i < 26; i++)
		last[i] = -1; // last 배열 -1로 초기화

	for (int i = 0; i < find.length(); i++) { // find의 모든 알파벳을 반복
		if (find[i] == 'X') { // X가 등장할 때 따로 예외처리
			X = i; // X의 마지막 등장 인덱스 저장
			continue; // 이하 구문 실행 안함
		}
			
		last[find[i] - 'a'] = i; // X가 아닐 때, 등장한 알파벳에서 'a'를 빼서 정수화 한 다음, 마지막 등장 인덱스 저장
	}
		
	return;
}

void BM(string s, string find) {
	int i = find.length() - 1;
	int j = find.length() - 1; // i, j를 찾고자하는 문자열의 마지막 알파벳으로 초기화

	do {
		if (s[i] == find[j] || find[j] == 'X') { // 비교하는 문자가 같거나, find의 알파벳이 X(아무 문자나 상관없음) 일 때
			if (j == 0) { // 마지막 인덱스까지 탐색 완료, 문자열 찾음
				v.push_back(i); // 등장 인덱스 저장

				i += find.length(); // 탐색을 계속 진행해야 하므로 처음 패턴이 등장하기 시작한 인덱스의 바로 다음으로 i를 이동시키기 위해 패턴을 더해준다.
				j = find.length() - 1; // 최초값으로 초기화

				cout << 1 << ' '; // find는 1칸 점프한것과 마찬가지이므로, 1 출력

				continue; // 이하 구문 실행 안함
			}

			i--;
			j--; // 다음 문자열 비교를 위해 i와 j를 1씩 감소

			continue;
		}
		
		// 비교하는 문자가 다를 때
		int l = last[s[i] - 'a'] > X ? last[s[i] - 'a'] : X; // X의 마지막 등장 인덱스와 현재 i에 해당하는 알파벳의 마지막 등장 인덱스를 비교하여 큰 값을 저장한다.
															 // X는 어떤 문자열과 매치되어도 상관이 없으므로, 둘 중 더 큰 값을 찾아서 최대한 많은 비교를 할 수 있도록 해야한다.
		cout << j + 1 - (j < l + 1 ? j : l + 1) << ' '; // 텍스트에서 등장한 알파벳이 find에 존재한다면 그 알파벳이 마지막으로 존재하는 find의 인덱스와 맞춰야 하므로, 이동하는 길이는 j + 1 - min(j, l + 1)이 된다.

		i += (find.length() - (j < l + 1 ? j : l + 1)); // 탐색을 계속 진행해야 하므로, i도 위와 동일하게 이동을 해준다.
		j = find.length() - 1; // 최초값으로 초기화
	
	} while (i < s.length()); // 해당 반복문을 문자열 끝까지 반복

	cout << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, find;
	cin >> s >> find; // 입력

	lastOccurrence(find);
	BM(s, find); // 각각의 함수 실행

	for (auto value : v) // index가 담긴 vector를 배열 기반 for문으로 하나씩 출력
		cout << value << ' ';

	return 0;
}

//--------------------------------------------------

// 2-1 KMP algorithm
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int fail[10002]; // 0으로 초기화된 failure 배열 생성, find의 최대길이는 10000이므로 넉넉하게 10002개 생성
//vector<int> v; // 구문을 찾았을 시 구문의 시작 인덱스 저장할 vector 선언
//
//void failure(string find) { // failure 함수 시작
//	int i = 1; 
//	int j = 0; // 반복되는 길이를 찾아야 하므로 j는 0으로, i는 한 칸 뒤로 초기화
//
//	while (i < find.length()) { // find의 길이만큼 반복
//		if (find[i] == find[j]) { // i와 j가 같다면 (접두와 접미가 같다면)
//			fail[i] = j + 1; // 공통된 접두, 접미사의 최대길이 저장
//			i++; 
//			j++; // i, j 모두 한 칸 이동
//		}
//		else if (j > 0) // i와 j가 다르고, j가 0보다 크다면
//			j = fail[j - 1]; // 다시 최대길이 찾아야 하므로 fail[j - 1]로 j를 이동한다.
//		else { // 공통된 접두, 접미사의 최대길이가 아예 없다면
//			fail[i] = 0; // i번째 failure 배열은 0
//			i++; // i 이동
//		}
//	}
// 
//	return;
//}
//
//void KMP(string s, string find) {
//	int i = 0;
//	int j = 0; // i와 j는 처음부터로 초기화
//
//	while (i < s.length()) {
//		if (s[i] == find[j]) { // 같은 문자를 찾았다면,
//			if (j == find.length() - 1) { // 현재 j가 find 문자열 길이보다 1보다 작다면 (find 문자열 마지막까지 비교를 끝마쳤다면)
//				v.push_back(i - j); // 찾고자 하는 문자열의 시작 인덱스 저장
//				
//				i += 1 - fail[j]; // 이미 탐색이 끝났으므로, 최대 failure 함수를 확인하여 i - fail[j]만큼 i 이동
//				j = 0; // 탐색이 끝났으므로, j는 0으로 초기화
//
//				cout << find.length() - fail[j] << ' '; // 이동한 길이 출력
//				continue;
//			}
//				
//			i++;
//			j++; // 마지막 인덱스가 아닐시 한칸 더 이동
//		}
//		else if (j > 0) {
//			cout << j - fail[j - 1] << ' '; // 이동한 만큼 출력
//			j = fail[j - 1]; // j에 새로운 인덱스 대입. fail[j - 1]보다 작은 값은 이미 failure 함수에 의해 확인할 필요가 없다.
//		}
//		else {
//			cout << 1 << ' '; // 1칸 이동
//			i++; // i 증가
//		}
//	}
//
//	cout << '\n'; // 개행 출력
//	return;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	string s, find; 
//	cin >> s >> find; // 전체 구문 s와 찾을 구문 find 입력
//
//	failure(find); // failure 배열 구하기 위해 find 입력
//	KMP(s, find); // KMP 알고리즘 시작
//
//	for (auto value : v)
//		cout << value << ' '; // 각 구문의 시작 인덱스 출력
//
//	return 0;
//}

//#include <iostream>
//#include <stack> 
//#include <vector>
//#include <list>
//#include <algorithm>
//using namespace std;
//
//struct element { // 인접한 정점의 정보와 학생 번호 저장할 구조체 선언
//	list<int> adj;
//	int index = -1;
//};
//
//vector<element> v; // 기본적인 입력값을 저장받을 element 구조체의 vectorㄴ
//vector<element> backtracking; // backtracking을 위해 v의 반대방향으로 저장될 vector
//vector<element> backtracking2; // 추후 sort 연산에 사용될 정렬되지 않은 backtracking vector
//bool visited[50001]; // 최초 DFS 실행 시 방문한 노드 정보를 저장할 배열
//bool backVisited[50001]; // backtracking 실행 시 방문할 노드 정보를 저장할 배열
//bool finished[50001]; // 최초 DFS 실행 시 DFS가 종료된 노드를 저장하기 위한 배열
//bool backFinished[50001]; // backtracking 실행 시 backtracking이 종료된 노드를 저장하기 위한 배열
//int sccLeader[50001]; // 각 학생의 SCC leader를 저장하기 위한 배열
//stack<int> s; // Finishing stack용 stack
//
//bool cmp(element a, element b) { // backtracking vector 정렬용 함수
//	if (a.adj.size() != b.adj.size()) // a의 list size(a의 팔로워)와, b의 list size(b의 팔로워)가 다르다면,
//		return a.adj.size() > b.adj.size(); // 팔로워가 많은 순으로 정렬
//	return a.index < b.index; // 같다면, 학생 번호가 작은 순으로 정렬
//}
//
//bool vcmp(const int& a, const int& b) { // v vector의 내부 list 정렬용 함수
//	if (backtracking2[a - 1].adj.size() != backtracking2[b - 1].adj.size()) // backtracking2를 참조하여, 각 학생의 팔로워 수가 다르다면,
//		return backtracking2[a - 1].adj.size() > backtracking2[b - 1].adj.size(); // 팔로워가 많은 순으로 정렬
//	return backtracking2[a - 1].index < backtracking2[b - 1].index; // 같다면, 학생 번호가 작은 순으로 정렬
//}
//
//void DFS(int cur) { // DFS 함수, cur은 실제 학생 번호에서 1이 작다.
//	if (finished[cur + 1]) // cur + 1이 이미 종료된 노드라면,
//		return; // 함수 종료
//
//	visited[cur + 1] = true; // cur + 1 방문했다고 알림
//
//	if (v[cur].adj.empty()) { // cur에서 더 이상 갈 수 있는 노드가 없다면,
//		cout << cur + 1 << ' '; // stack에 넣을 것이므로, 출력
//		s.push(cur + 1); // finishing stack에 삽입
//		finished[cur + 1] = true; // cur + 1이 finishing stack에 들어갔다고 알림
//		return;
//	}
//
//	for (auto value : v[cur].adj) { // cur번째의 node에서 갈 수 있는 정점들을 모두 확인한다.
//		if (!visited[value]) // 아직 방문하지 않았다면, 
//			DFS(value - 1); // 실제 학생 번호에서 1을 뺀 값으로 DFS 재귀 실행
//	}
//
//	// cur + 1이 아직 finishing stack에 없는데, for문을 모두 수행했다면, 더 이상 갈 곳이 없는 것이므로 finish 되어야 한다.
//	if (!finished[cur + 1]) { 
//		cout << cur + 1 << ' '; // stack에 넣을 것이므로, 출력
//		finished[cur + 1] = true; // cur + 1이 finishing stack에 들어갔다고 알림
//		s.push(cur + 1); // finishing stack에 삽입
//		return;
//	}
//}
//
//void getLeader(int cur, int leader) { // SCC의 leader를 구하는 함수, cur과 leader를 매개변수로 받아서, leader를 SCC의 leader로 지정한다.
//	if (backFinished[cur]) // cur이 이미 종료된 노드라면,
//		return; // 함수 종료
//
//	backVisited[cur] = true; // cur 방문했다고 알림
//
//	if (backtracking2[cur - 1].adj.empty()) { // backtracking2 vector의 cur - 1 번쨰 index에서 더 이상 갈 수 있는 정점이 없다면,
//		sccLeader[cur] = leader; // 학생번호 cur번의 leader 설정
//		backFinished[cur] = true; // backtracking 종료되었다고 알림
//		return; // 함수 종료
//	}
//
//	for (auto value : backtracking2[cur - 1].adj) { // backtracking2 vector의 cur - 1번째의 node에서 갈 수 있는 정점들 모두 확인한다.
//		if (!backVisited[value]) // 아직 방문하지 않았다면,
//			getLeader(value, leader); // getLeader 재귀 실행
//	}
//
//	// for문이 종료되었다면, 더 이상 갈 정점이 없는 것이므로, finish 되어야 한다.
//	if (!backFinished[cur]) {
//		sccLeader[cur] = leader; // leader 설정
//		backFinished[cur] = true; // cur번째 node가 finish 되었다고 알림
//		return;
//	}
//}
//
//int main() {
//	int n, m; // vertex, edge 수 입력
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++) { // 벡터들 초기화, 최초의 index는 i로 지정하여 입력되지 않는 edge도 계산할 수 있게 한다.
//		element e;
//		e.index = i;
//		v.push_back(e);
//		backtracking.push_back(e);
//		backtracking2.push_back(e);
//	}
//
//	for (int i = 0; i < m; i++) { // edge 정보 입력
//		int src, dst;
//		cin >> src >> dst;
//		v[src - 1].adj.push_back(dst); // 배열의 index가 되어야 하므로 src에서 1을 빼서 dst 삽입
//		v[src - 1].index = src - 1;
//
//		backtracking[dst - 1].adj.push_back(src); // v와 반대방향으로 삽입
//		backtracking[dst - 1].index = dst - 1;
//
//		backtracking2[dst - 1].adj.push_back(src); // backtracking과 동일하게 삽입
//		backtracking2[dst - 1].index = dst - 1;
//	}
//
//	sort(backtracking.begin(), backtracking.end(), cmp); // cmp 함수를 기준으로 backtracking vector 정렬
//
//	for (int i = 0; i < n; i++) 
//		v[i].adj.sort(vcmp); // vcmp 함수를 기준으로 v의 내부 list 값 정렬
//
//	for (int i = 0; i < n; i++)
//		DFS(backtracking[i].index); // 정렬된 backtracking vector의 학생 번호 순으로 DFS 실행
//	cout << '\n';
//
//	for (int i = 0; i < n; i++) { // 만들어진 finishing stack의 top을 기준으로 getLeader 실행
//		getLeader(s.top(), s.top());
//		s.pop(); // 한 번의 시행 후, pop()으로 맨 위 요소 제거
//	}
//
//	for (int i = 1; i <= n; i++)
//		cout << sccLeader[i] << ' '; // 각 scc의 Leader 출력
//		
//	return 0;
//}
