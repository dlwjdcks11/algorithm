//#include <iostream>
//#include <vector>
//using namespace std;
//
//void solve() {
//	int n;
//	cin >> n;
//	vector<int> signal;
//
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		cin >> tmp;
//		signal.push_back(tmp);
//	}
//
//	for (int i = 1; i <= n; i++) {
//		bool f = true;
//		vector<int> tmp = vector<int>(signal.begin(), signal.begin() + i);
//		vector<int> answer = tmp;
//
//		for (int j = 0; j < n; j += i) {
//			vector<int> compare;
//			int size = i + j;
//			if (size > n) {
//				compare = vector<int>(signal.begin() + j, signal.end());
//			}
//			else {
//				compare = vector<int>(signal.begin() + j, signal.begin() + i + j);
//			}
//
//			if (compare.size() != tmp.size()) {
//				if (tmp.size() > compare.size())
//					tmp = vector<int>(tmp.begin(), tmp.begin() + compare.size());
//				else if (compare.size() > tmp.size())
//					compare = vector<int>(compare.begin(), compare.begin() + signal.size());
//			}
//				
//			if (tmp != compare) {
//				f = false;
//				break;
//			}
//		}
//
//		if (f) {
//			for (int i = 0; i < answer.size(); i++)
//				cout << answer[i] << ' ';
//			cout << '\n';
//			return;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int T;
//	cin >> T;
//	while (T--)
//		solve();
//
//	return 0;
//}