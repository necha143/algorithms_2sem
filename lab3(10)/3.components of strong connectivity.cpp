#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> graph_G;
vector<vector<int>> graph_H;
vector<int> mark;
vector<bool> visited;
stack<int> order;

void dfs1(int v) {
    visited[v] = true;
    for (int u: graph_G[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    order.push(v);
}

void dfs2(int v, int numComp) {
    mark[v] = numComp;
    for (int u: graph_H[v]) {
        if (mark[u] == 0) {
            dfs2(u, numComp);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    graph_G.resize(N, vector<int>(0));
    graph_H.resize(N, vector<int>(0));
    mark.resize(N);
    for (int j = 0; j < N; j++) {
        mark[j] = 0;
    }
    visited.resize(N+1);
    for (int j = 0; j < N; j++) {
        visited[j] = false;
    }

    for (int i = 0; i < M; i++) {
        int top1, top2;
        cin >> top1 >> top2;

        graph_G[top1 - 1].push_back(top2 - 1);
        graph_H[top2 - 1].push_back(top1 - 1);
    }


    for (int i = 0; i < Q; i++) {
        int top1, top2;
        cin >> top1 >> top2;

        for (int j = 0; j < N; j++) {
            if (!visited[j]) {
                dfs1(j);
            }
        }

        int numComp = 0;
        while (!order.empty()){
            int v=order.top();
            order.pop();
            if (mark[v] == 0) {
                numComp++;
                dfs2(v, numComp);
            }
        }

        if (mark[top1-1] == mark[top2-1]){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}