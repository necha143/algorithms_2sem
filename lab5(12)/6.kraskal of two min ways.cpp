#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Edge {
    long from;
    long to;
    long weight;
};

int find_Set(int top, vector<int> &parent) {
    if (top == parent[top]) {
        return top;
    }
    return parent[top] = find_Set(parent[top], parent);
}

void union_Sets(int top1, int top2, vector<int> &rank, vector<int> &parent) {
    top1 = find_Set(top1, parent);
    top2 = find_Set(top2, parent);

    if (top1 != top2) {
        if (rank[top1] < rank[top2]) {
            parent[top1] = top2;
        } else if (rank[top1] > rank[top2]) {
            parent[top2] = top1;
        } else {
            parent[top1] = top2;
            rank[top2] += 1;
        }
    }
}

void kraskal(vector<Edge> edges, vector<Edge> mst, int M, vector<int> &parent, vector<int> &rank, int N) {
    long weight_1 = 0;
    int top1, top2;
    Edge skipped = Edge(0, 0, 0);
    for (int i = 0; i < M; i++) {
        top1 = find_Set(edges[i].from, parent);
        top2 = find_Set(edges[i].to, parent);
        if (top1 != top2) {
            mst.push_back(edges[i]);
            weight_1 += edges[i].weight;
            union_Sets(top1, top2, rank, parent);
        } else if (skipped.from == 0) {
            skipped = edges[i];
        }
    }

    parent.clear();
    rank.clear();
    for (int i = 0; i < N; i++) {
        parent.push_back(i);
        rank.push_back(1);
    }

    long weight_2 = skipped.weight;
    union_Sets(skipped.from, skipped.to, rank, parent);
    for (int i = 0; i < M; i++) {
        top1 = find_Set(edges[i].from, parent);
        top2 = find_Set(edges[i].to, parent);
        if (top1 != top2) {
            mst.push_back(edges[i]);
            weight_2 += edges[i].weight;
            union_Sets(top1, top2, rank, parent);
        }
    }

    cout << weight_1 << " " << weight_2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    vector<Edge> mst;
    vector<int> parent;
    vector<int> rank;
    for (int i = 0; i < N; i++) {
        parent.push_back(i);
        rank.push_back(1);
    }
    for (int i = 0; i < M; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back(Edge{from - 1, to - 1, weight});
    }

    sort(edges.begin(), edges.end(), [](Edge const &a, Edge const &b) { return a.weight < b.weight; });
    kraskal(edges, mst, M, parent, rank, N);
    return 0;
}
