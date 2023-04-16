#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

void Relax(int *dist, int *prev, Edge edge, bool &flag) {
    if (dist[edge.to] > dist[edge.from] + edge.weight) {
        dist[edge.to] = dist[edge.from] + edge.weight;
        prev[edge.to] = edge.from;
        flag = true;
    }
}

void InitSource(vector<Edge> &edges, int n, int *dist, int *prev) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        prev[i] = INT_MIN;
    }
    dist[edges[0].from] = 0;
}

void CheckCycles(vector<Edge> &edges, int *dist, int *prev, int n, int k) {
    int ans = 0;

    for (Edge edge: edges) {
        if (dist[edge.to] > dist[edge.from] + edge.weight) {
            for (int i = 0; i < n - 1; i++) {
                edge.to = prev[edge.to];
            }

            edge.from = edge.to;
            while (edge.from != prev[edge.to]) { //возьмём вершину, расстояние до которой изменилось, и будем идти от неё по предкам,
                ans++;                           //пока не войдём в цикл; этот цикл и будет искомым отрицательным циклом.
                edge.to = prev[edge.to];
            }
        }
    }

    (ans < k or !ans) ? cout << "YES" << "\n" : cout << "NO" << "\n";
}

void ford_bellman(vector<Edge> &edges, int n, int k) {
    int dist[n];
    int prev[n];
    InitSource(edges, n, dist, prev);

    bool flag;
    for (int i = 0; i < n - 1; i++) {
        flag = false;
        for (Edge edge: edges) {
            Relax(dist, prev, edge, flag);
        }
        if (!flag) break;
    }

    CheckCycles(edges, dist, prev, n, k);
}

int main() {
    int N, k;
    cin >> N >> k;

    while (N > 0) {

        int n, m;
        cin >> n >> m;
        vector<Edge> edges;
        for (int i = 0; i < m; i++) {
            int start, end, w;
            cin >> start >> end >> w;
            edges.push_back(Edge{start - 1, end - 1, w});
        }
        ford_bellman(edges, n, k);

        N--;
    }

    return 0;
}