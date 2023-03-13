#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> dist;
vector<char> color;


void BFS(int start, int end) {
    color[start] = 'G';
    dist[start] = 0;
    queue<int> Q;
    Q.push(start);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (color[v] == 'W' and (dist[u] + 1) < dist[v]) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
            if (v == end) {
                cout << dist[v];
                return;
            }
        }
        color[u] = 'B';
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    graph.resize(N, vector<int>(0));
    dist.resize(N, N + 1);
    color.resize(N, 'W');

    for (int i = 0; i < M; i++) {
        int top1, top2;
        cin >> top1 >> top2;

        graph[top1 - 1].push_back(top2 - 1);
        graph[top2 - 1].push_back(top1 - 1);
    }

    int S, F;
    cin >> S >> F;

    BFS(S - 1, F - 1);

    return 0;
}
