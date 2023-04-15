#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
    int length;
};

void ford_bellman(int n, vector<Edge> edges) {
    int dist[n];
    int prev[n];
    for (int i = 0; i < n; i++) {
        dist[i] = 1;
        prev[i] = -1;
    }
    dist[edges[0].from] = 0;
    int x;
    for (int i = 0; i < n - 1; i++) {
        x = -1;
        for (auto edge: edges) {
            if (dist[edge.to] > dist[edge.from] + edge.length) {
                dist[edge.to] = dist[edge.from] + edge.length;
                prev[edge.to] = edge.from;
                x = edge.to;
            }
        }
    }
    if (x == -1) {
        cout << "NO";
        return;
    } else {
        cout << "YES";
        return;
    }


}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int from, to, l;
        cin >> from >> to >> l;
        edges.push_back(Edge{from - 1, to - 1, l});
    }

    ford_bellman(n, edges);
    return 0;
}