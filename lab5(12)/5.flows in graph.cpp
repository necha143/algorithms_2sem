#include <iostream>
#include <queue>
using namespace std;

struct Edge {
    long from;
    long to;
    long weight;
};

class ford_falkerson {
    char BFS(int start, int end, int N, vector<char> &color, vector<int> &parent, vector<vector<int>> &weights) {
        for (int i = 0; i < N; i++) {
            color[i] = 'W';
        }
        queue<int> Q;
        Q.push(start);
        color[start] = 'B';

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (int v = 0; v < N; v++) {
                if (color[v] == 'W' && weights[u][v] > 0) {
                    color[v] = 'B';
                    parent[v] = u;
                    Q.push(v);
                }
            }
        }

        return color[end];
    }

public:
/*Идея - на каждой итерации находить увеличивающий путь в остаточной сети и увеличивать поток по этому пути.
Увеличивающий путь — это путь из источника в сток, по которому все ребра имеют неиспользованные пропускные способности.*/
    void Flow(int start, int end, int N, vector<char> &color, vector<int> &parent, vector<vector<int>> &weights,
              vector<Edge> &edges) {
        int max_flow = 0;
        while (BFS(start, end, N, color, parent, weights) == 'B') {
            int path_flow = INT_MAX;

            for (int v = end; v != start; v = parent[v]) {
                int u = parent[v];
                if (weights[u][v] < path_flow) {
                    path_flow = weights[u][v];
                }
            }

            for (int v = end; v != start; v = parent[v]) {
                int u = parent[v];
                weights[u][v] -= path_flow;
                weights[v][u] += path_flow;
            }

            max_flow += path_flow;
        }

        cout << max_flow;
    }
} fordFalkerson;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    vector<char> color(M);
    vector<int> parent(M);
    vector<vector<int>> weights(M, vector<int>(M));
    for (int i = 0; i < M; i++) {
        int top1, top2, weight;
        cin >> top1 >> top2 >> weight;
        edges.push_back(Edge{top1 - 1, top2 - 1, weight});
        weights[top1 - 1][top2 - 1] = weight;
    }

    fordFalkerson.Flow(0, N - 1, N, color, parent, weights, edges);
    return 0;
}
