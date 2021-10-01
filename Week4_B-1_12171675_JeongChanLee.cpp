//#include <iostream>
//using namespace std;
//
//struct Point {
//	int x;
//	int y;
//};
//
//void swap(Point &p1, Point &p2) { // ����Ʈ �ٲ� ��ǥ
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
//	if (p1.x == p2.x) // X��ǥ�� ���ٸ� ���Ⱑ ���Ѵ��̹Ƿ�, 1�� �������ְ�, �ƴ϶�� 0���� �������ش�.
//		m1 = 1;
//	else
//		m1 = 0;
//	if (p3.x == p4.x)
//		m2 = 1;
//	else
//		m2 = 0;
//
//	if (m1 == m2) { // ���� ���� ��,
//		if (m1 == 0) { // ������ X�࿡ �����ϸ�,
//			if (p1.y != p3.y) { // �� ������ y��ǥ�� �ٸ��� ���� ���� ����.
//				cout << 1 << '\n';
//				return;
//			}
//			else {
//				if (p1.x > p2.x)
//					swap(p1, p2);
//				if (p3.x > p4.x) // p1, p2, p3, p4�� ���� ũ������ ����
//					swap(p3, p4);
//
//				if (((p1.x < p3.x) && (p2.x < p3.x)) || ((p1.x > p4.x) && (p2.x > p4.x))) { // �� ���� ��
//					cout << 1 << '\n';
//					return;
//				}
//				if (((p1.x < p3.x) && (p2.x == p3.x)) || ((p1.x == p4.x) && (p2.x > p4.x))) { // �� ������ ���� ��
//					cout << 2 << '\n';
//					return;
//				}
//				if (((p1.x < p3.x) && (p3.x < p2.x) && (p2.x < p4.x)) || ((p3.x < p1.x) && (p1.x < p4.x) && (p4.x < p2.x))) { // �Ϻΰ� ���Ե� ��
//					cout << 3 << '\n';
//					return;
//				}
//				if (((p1.x <= p3.x) && (p2.x >= p4.x)) || ((p3.x <= p1.x) && (p4.x >= p2.x))) { // ���ΰ� ���θ� ������ ��
//					cout << 4 << '\n';
//					return;
//				}
//			}
//		}
//		else { // ������ y�࿡ �����ϸ�,
//			if (p1.x != p3.x) { // �� ������ x��ǥ�� �ٸ��� ���� ���� ����.
//				cout << 1 << '\n';
//				return;
//			}
//			else {
//				if (p1.y > p2.y)
//					swap(p1, p2);
//				if (p3.y > p4.y) // p1, p2, p3, p4�� ���� ũ������ ����
//					swap(p3, p4);
//
//				if (((p1.y < p3.y) && (p2.y < p3.y)) || ((p1.y > p4.y) && (p2.y > p4.y))) { // �� ���� ��
//					cout << 1 << '\n';
//					return;
//				}
//				if (((p1.y < p3.y) && (p2.y == p3.y)) || ((p1.y == p4.y) && (p2.y > p4.y))) { // �� ������ ���� ��
//					cout << 2 << '\n';
//					return;
//				}
//				if (((p1.y < p3.y) && (p3.y < p2.y) && (p2.y < p4.y)) || ((p3.y < p1.y) && (p1.y < p4.y) && (p4.y < p2.y))) { // �Ϻΰ� ���Ե� ��
//					cout << 3 << '\n';
//					return;
//				}
//				if (((p1.y <= p3.y) && (p2.y >= p4.y)) || ((p3.y <= p1.y) && (p4.y >= p2.y))) { // ���ΰ� ���θ� ������ ��
//					cout << 4 << '\n';
//					return;
//				}
//			}
//		}
//	}
//	else { // ���� �ٸ� ��
//		if (m1 == 0) { // p1, p2�� �̷���� ������ x�࿡ �����ϴٸ�,
//			if (p1.x > p2.x) // ���� ũ������ ����
//				swap(p1, p2);
//			if (p3.y > p4.y)
//				swap(p3, p4);
//
//			if (((p3.y <= p1.y) && (p1.y <= p4.y)) && ((p1.x <= p3.x) && (p3.x <= p2.x))) { // �� ������ �����ٸ�,
//				cout << 2 << '\n';
//				return;
//			}
//			else {
//				cout << 1 << '\n';
//				return;
//			}
//		}
//		else { // p1. p2�� �̷���� ������ y�࿡ �����ϴٸ�,
//			if (p1.y > p2.y) // ���� ũ������ ����
//				swap(p1, p2);
//			if (p3.x > p4.x)
//				swap(p3, p4);
//
//			if (((p3.x <= p1.x) && (p1.x <= p4.x)) && ((p1.y <= p3.y) && (p3.y <= p2.y))) { // �� ������ �����ٸ�,
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