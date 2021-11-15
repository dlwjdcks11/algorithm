//#include <iostream>
//using namespace std;
//
//void solve() {
//	int n;
//	int redP = 0, red = 0, blueP = 0, blue = 0;
//	cin >> n;
//
//	char** matrix = new char*[n + 1];
//	for (int i = 0; i < n + 1; i++) {
//		matrix[i] = new char[n + 1];
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> matrix[i][j];
//		}
//	}
//
//	cout << redP << red << blueP << blue << '\n';
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