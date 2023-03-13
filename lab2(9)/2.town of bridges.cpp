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
        if (color[i] == 'G') {
            cout << "YES";
            exit(0);
        }
    }

    color[start] = 'B';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    graph.resize(N, vector<int>(0));
    color.resize(N, 'W');

    for (int i = 0; i < M; i++) {
        int top1, top2;
        cin >> top1 >> top2;
        graph[top1 - 1].push_back(top2 - 1);
        graph[top2 - 1].push_back(top1 - 1);
    }

    for (int i = 0; i < N; i++) {
        DFS(i, 0);
    }
    cout << "NO";

    return 0;
}
