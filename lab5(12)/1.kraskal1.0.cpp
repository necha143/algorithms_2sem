/*
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
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

int kruskal(vector<Edge> edges, vector<Edge> mst, int M, vector<int> &parent, vector<int> &rank) {
    int weight = 0;
    int top1, top2;
    for (int i = 0; i < M; i++) {
        top1 = find_Set(edges[i].from, parent);
        top2 = find_Set(edges[i].to, parent);
        if (top1 != top2) {
            mst.push_back(edges[i]);
            weight += edges[i].weight;
            union_Sets(top1, top2, rank, parent);
        }
    }
    return weight;
}

int main() {
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
    cout << kruskal(edges, mst, M, parent, rank);
    return 0;
}*/
