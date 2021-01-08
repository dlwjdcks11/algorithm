//���� 11728
#include <iostream>
#include <vector>
using namespace std;

int MIN = 1; // MIN Heap ������ ��

class Heap { // �� ����
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

Heap::Heap() { // 0��°���� �����Ⱚ �ְ�, �� �ʱ�ȭ
	v.push_back(-1);
	this->heapSize = 0;
	this->rootIndex = 1;
	this->direction = MIN;
}

void Heap::swap(int idx1, int idx2) { // ���� �� ����
	int tmp = v[idx1];
	v[idx1] = v[idx2];
	v[idx2] = tmp;
}

void Heap::upHeap(int idx) { // upHeap ������
	if (idx == rootIndex) // �� ���� �����ߴٸ� ����
		return;

	int parent = idx / 2;
	if (v[parent] * direction > v[idx] * direction) { // MIN Heap�̹Ƿ�, �θ� ��尡 �ڽ� ��庸�� ũ�ٸ�,
		swap(parent, idx); // �ڸ� �ٲٱ�
		upHeap(parent); // ����ؼ� �ö�
	}
}

void Heap::downHeap(int idx) { //downHeap ������
	int left = idx * 2; // �θ��� ���� ��� �ε���
	int right = idx * 2 + 1; // �θ��� ������ ��� �ε���

	if (right <= heapSize) { // �����ʰ� ���ʿ� ��� ��尡 �ִٸ�
		if (v[left] * direction <= v[right] * direction) { // ���� ��尡 ������ ��庸�� �۴ٸ�,(MIN Heap)
			if (v[left] * direction < v[idx] * direction) { // ���� ��尡 �θ� ��庸�ٵ� �۴ٸ�,
				swap(left, idx); // ��ü
				downHeap(left); // ����ؼ� ������
			}
			else
				return;
		}
		else {
			if (v[right] * direction < v[idx] * direction) { // ������ ��尡 �θ� ��庸�ٵ� �۴ٸ�,
				swap(right, idx); // ��ü
				downHeap(right); // ����ؼ� ������
			}
			else
				return;
		}
	}
	else if (left <= heapSize) { // ���ʿ��� �ڽ� ��尡 �ִٸ�
		if (v[left] * direction < v[idx] * direction) { // ���� ����
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
	upHeap(heapSize); //���� ��, ������ index�������� upHeap ����, ��� Heap�� ��� ����
}

int Heap::pop() {
	int top = v[rootIndex];
	v[rootIndex] = v[heapSize];
	v.pop_back();
	this->heapSize--;
	downHeap(rootIndex); // ù���� ���� ������ ��� ��ȯ ��, ù��° ��忡������ downHeap ����, ��� Heap ����

	return top; // ù ���� ��� return
}

int Heap::size() { //���� Heap�� size return
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