#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// first = neighbor, second = distance
int answer = 0;

int search(int n, vector<pair<int, int>> house[], bool visited[]) {
    int maxD = 0;
    int secondD = 0;
    int tmpD;

    visited[n] = true;
    for (int i = 0; i < house[n].size(); i++) {
        if (visited[house[n][i].first] == false) {
            tmpD = search(house[n][i].first, house, visited) + house[n][i].second;
            if (tmpD > maxD)
                swap(tmpD, maxD);
            if (tmpD > secondD)
                swap(tmpD, secondD);
        }
    }
    answer = max(answer, maxD + secondD);
    return maxD;
}

void solve() {
    vector<pair<int, int>> house[2001];
    bool visited[2001];

    for (int i = 0; i < 2001; i++)
        visited[i] = false;

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        house[u].push_back({ v, d });
        house[v].push_back({ u, d });
    }

    answer = 0;
    search(1, house, visited);
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}