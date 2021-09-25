#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
	vector<int> children;
	int parent = 0;
	int length = 0;
};

void travel(int idx, Node tree[], int answer[]) {
	if (idx == 1)
		answer[idx] = 4;
	else
		answer[idx] = answer[tree[idx].parent] + 1 + tree[idx].length;

	for (int i = 0; i < tree[idx].children.size(); i++)
		travel(tree[idx].children[i], tree, answer);
}

void solve() {
	int n;
	cin >> n;

	Node* tree = new Node[n + 1];
	int* answer = new int[n + 1];

	for (int i = 0; i < n - 1; i++) {
		int src, dst;
		cin >> src >> dst;

		tree[src].children.push_back(dst);
		tree[dst].parent = src;
	}

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		tree[i].length = s.size();
	}

	travel(1, tree, answer);

	for (int i = 1; i <= n; i++)
		cout << answer[i] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}