#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

void Relax(int *dist, Edge edge, bool &flag) {
    if (dist[edge.to] > dist[edge.from] + edge.weight) {
        dist[edge.to] = dist[edge.from] + edge.weight;
        flag = true;
    }
}

void InitSource(int n, int *dist, int start) {
    for (int i = 0; i < 100000; i++) {
        dist[i] = 1000000;
    }
    dist[start - 1] = 0;
}

void CheckDist(int q, int *dist) {
    int destination;
    while (q > 0) {
        cin >> destination;
        if (dist[destination - 1] == 1000000) {
            cout << "-1" << "\n";
        } else {
            cout << dist[destination - 1] << "\n";
        }
        q--;
    }
}

void ford_bellman(vector<Edge> &edges, int n, int q, int start) {
    int dist[100000];
    InitSource(n, dist, start);

    bool flag;
    for (int i = 0; i < n - 1; i++) {
        flag = false;
        for (Edge edge: edges) {
            Relax(dist, edge, flag);
        }
        if (!flag) break;
    }

    CheckDist(q, dist);
}

int main() {
    int N, M, Q, start;
    cin >> N >> M >> Q >> start;

    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back(Edge{from - 1, to - 1, weight});
        edges.push_back(Edge{to - 1, from - 1, weight});
    }

    ford_bellman(edges, N, Q, start);

    return 0;
}