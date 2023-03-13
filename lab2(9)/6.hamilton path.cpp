#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<char> color;

void DFS(int start, int prev) {
    color[start] = 'G';

    for (int i: graph[start]) {
        if (i == prev) {
            continue;
        }
        if (color[i] == 'W') {
            DFS(i, start);
        }
    }

    color[start] = 'B';
}

void bypass(int n) {
    int cnt1 = 0, cnt2 = 0;

    for (vector<int> i: graph) {
        if (i.size() == 1) {
            cnt1++;
        } else if (i.size() == 2) {
            cnt2++;
        } else {
            cout << "NO";
            exit(0);
        }
    }

    (cnt2 == n - 2 and cnt1 == 2) ? cout << "YES" : cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.resize(n, vector<int>());
    color.resize(n, 'W');

    for (int i = 0; i < m; i++) {
        int top1, top2;
        cin >> top1 >> top2;
        graph[top1 - 1].push_back(top2 - 1);
        graph[top2 - 1].push_back(top1 - 1);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] != 'B') {
            DFS(i, -1);
            count++;
        }
    }

    if (count != 1) {
        cout << "NO";
        return 0;
    } else {
        bypass(n);
    }
    return 0;
};
