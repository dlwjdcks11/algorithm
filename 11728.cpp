//백준 11728
#include <iostream>
#include <vector>
using namespace std;

int MIN = 1; // MIN Heap 구현할 것

class Heap { // 힙 구현
private:
	vector<int> v;
	int heapSize;
	int rootIndex;
	int direction;

public:
	Heap();
	void swap(int, int);
	void upHeap(int);
	void downHeap(int);
	void insert(int);
	int pop();
	int size();
};

Heap::Heap() { // 0번째에는 쓰레기값 넣고, 값 초기화
	v.push_back(-1);
	this->heapSize = 0;
	this->rootIndex = 1;
	this->direction = MIN;
}

void Heap::swap(int idx1, int idx2) { // 벡터 값 변경
	int tmp = v[idx1];
	v[idx1] = v[idx2];
	v[idx2] = tmp;
}

void Heap::upHeap(int idx) { // upHeap 구현부
	if (idx == rootIndex) // 맨 위에 도착했다면 리턴
		return;

	int parent = idx / 2;
	if (v[parent] * direction > v[idx] * direction) { // MIN Heap이므로, 부모 노드가 자식 노드보다 크다면,
		swap(parent, idx); // 자리 바꾸기
		upHeap(parent); // 계속해서 올라감
	}
}

void Heap::downHeap(int idx) { //downHeap 구현부
	int left = idx * 2; // 부모의 왼쪽 노드 인덱스
	int right = idx * 2 + 1; // 부모의 오른쪽 노드 인덱스

	if (right <= heapSize) { // 오른쪽과 왼쪽에 모두 노드가 있다면
		if (v[left] * direction <= v[right] * direction) { // 왼쪽 노드가 오른쪽 노드보다 작다면,(MIN Heap)
			if (v[left] * direction < v[idx] * direction) { // 왼쪽 노드가 부모 노드보다도 작다면,
				swap(left, idx); // 교체
				downHeap(left); // 계속해서 내려감
			}
			else
				return;
		}
		else {
			if (v[right] * direction < v[idx] * direction) { // 오른쪽 노드가 부모 노드보다도 작다면,
				swap(right, idx); // 교체
				downHeap(right); // 계속해서 내려감
			}
			else
				return;
		}
	}
	else if (left <= heapSize) { // 왼쪽에만 자식 노드가 있다면
		if (v[left] * direction < v[idx] * direction) { // 위와 동일
			swap(left, idx);
			downHeap(left);
		}
		else
			return;
	}
	else
		return;
}

void Heap::insert(int n) {
	v.push_back(n);
	this->heapSize++;
	upHeap(heapSize); //삽입 후, 마지막 index에서부터 upHeap 시작, 계속 Heap의 모습 유지
}

int Heap::pop() {
	int top = v[rootIndex];
	v[rootIndex] = v[heapSize];
	v.pop_back();
	this->heapSize--;
	downHeap(rootIndex); // 첫번쨰 노드와 마지막 노드 교환 후, 첫번째 노드에서부터 downHeap 시작, 계속 Heap 유지

	return top; // 첫 번쨰 노드 return
}

int Heap::size() { //현재 Heap의 size return
	return this->heapSize;
}

int main() {
	ios::sync_with_stdio(false);
	Heap h;
	int n, m, tmp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		h.insert(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		h.insert(tmp);
	}
	int size = h.size();

	for (int i = 0; i < size; i++)
		cout << h.pop() << " ";
	cout << '\n';

	return 0;
}