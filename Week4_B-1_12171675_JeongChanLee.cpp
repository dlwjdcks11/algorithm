//#include <iostream>
//using namespace std;
//
//struct Point {
//	int x;
//	int y;
//};
//
//void swap(Point &p1, Point &p2) { // 포인트 바꿀 좌표
//	Point t;
//
//	t = p1;
//	p1 = p2;
//	p2 = t;
//}
//
//void solve() {
//	Point p1;
//	Point p2;
//	Point p3;
//	Point p4;
//	int m1, m2;
//	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
//
//	if (p1.x == p2.x) // X좌표가 같다면 기울기가 무한대이므로, 1로 설정해주고, 아니라면 0으로 설정해준다.
//		m1 = 1;
//	else
//		m1 = 0;
//	if (p3.x == p4.x)
//		m2 = 1;
//	else
//		m2 = 0;
//
//	if (m1 == m2) { // 기울기 같을 때,
//		if (m1 == 0) { // 직선이 X축에 평행하면,
//			if (p1.y != p3.y) { // 두 직선의 y좌표가 다르면 만날 일이 없다.
//				cout << 1 << '\n';
//				return;
//			}
//			else {
//				if (p1.x > p2.x)
//					swap(p1, p2);
//				if (p3.x > p4.x) // p1, p2, p3, p4를 각각 크기순대로 정렬
//					swap(p3, p4);
//
//				if (((p1.x < p3.x) && (p2.x < p3.x)) || ((p1.x > p4.x) && (p2.x > p4.x))) { // 안 만날 때
//					cout << 1 << '\n';
//					return;
//				}
//				if (((p1.x < p3.x) && (p2.x == p3.x)) || ((p1.x == p4.x) && (p2.x > p4.x))) { // 한 점에서 만날 때
//					cout << 2 << '\n';
//					return;
//				}
//				if (((p1.x < p3.x) && (p3.x < p2.x) && (p2.x < p4.x)) || ((p3.x < p1.x) && (p1.x < p4.x) && (p4.x < p2.x))) { // 일부가 포함될 때
//					cout << 3 << '\n';
//					return;
//				}
//				if (((p1.x <= p3.x) && (p2.x >= p4.x)) || ((p3.x <= p1.x) && (p4.x >= p2.x))) { // 서로가 서로를 포함할 때
//					cout << 4 << '\n';
//					return;
//				}
//			}
//		}
//		else { // 직선이 y축에 평행하면,
//			if (p1.x != p3.x) { // 두 직선의 x좌표가 다르면 만날 일이 없다.
//				cout << 1 << '\n';
//				return;
//			}
//			else {
//				if (p1.y > p2.y)
//					swap(p1, p2);
//				if (p3.y > p4.y) // p1, p2, p3, p4를 각각 크기순대로 정렬
//					swap(p3, p4);
//
//				if (((p1.y < p3.y) && (p2.y < p3.y)) || ((p1.y > p4.y) && (p2.y > p4.y))) { // 안 만날 때
//					cout << 1 << '\n';
//					return;
//				}
//				if (((p1.y < p3.y) && (p2.y == p3.y)) || ((p1.y == p4.y) && (p2.y > p4.y))) { // 한 점에서 만날 때
//					cout << 2 << '\n';
//					return;
//				}
//				if (((p1.y < p3.y) && (p3.y < p2.y) && (p2.y < p4.y)) || ((p3.y < p1.y) && (p1.y < p4.y) && (p4.y < p2.y))) { // 일부가 포함될 때
//					cout << 3 << '\n';
//					return;
//				}
//				if (((p1.y <= p3.y) && (p2.y >= p4.y)) || ((p3.y <= p1.y) && (p4.y >= p2.y))) { // 서로가 서로를 포함할 때
//					cout << 4 << '\n';
//					return;
//				}
//			}
//		}
//	}
//	else { // 기울기 다를 때
//		if (m1 == 0) { // p1, p2로 이루어진 직선만 x축에 평행하다면,
//			if (p1.x > p2.x) // 각각 크기순대로 정렬
//				swap(p1, p2);
//			if (p3.y > p4.y)
//				swap(p3, p4);
//
//			if (((p3.y <= p1.y) && (p1.y <= p4.y)) && ((p1.x <= p3.x) && (p3.x <= p2.x))) { // 한 점에서 만난다면,
//				cout << 2 << '\n';
//				return;
//			}
//			else {
//				cout << 1 << '\n';
//				return;
//			}
//		}
//		else { // p1. p2로 이루어진 직선만 y축에 평행하다면,
//			if (p1.y > p2.y) // 각각 크기순대로 정렬
//				swap(p1, p2);
//			if (p3.x > p4.x)
//				swap(p3, p4);
//
//			if (((p3.x <= p1.x) && (p1.x <= p4.x)) && ((p1.y <= p3.y) && (p3.y <= p2.y))) { // 한 점에서 만난다면,
//				cout << 2 << '\n';
//				return;
//			}
//			else {
//				cout << 1 << '\n';
//				return;
//			}
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