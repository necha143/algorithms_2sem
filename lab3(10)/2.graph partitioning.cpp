#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<char> color;


void BFS(int start, int end) {
    color[start] = 'G';
    queue<int> Q;
    Q.push(start);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (color[v] == 'W') {
                Q.push(v);
            }
            if (v == end) {
                cout << "YES" << "\n";
                return;
            }
        }
        color[u] = 'B';
    }
    cout << "NO" << "\n";
}

void edge_delete(int top1, int top2) {
    int ind = 0;
    while (graph[top1][ind] != top2) {
        ind++;
    }
    graph[top1].erase(graph[top1].begin() + ind);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;
    graph.resize(N, vector<int>(0));
    color.resize(N, 'W');

    for (int i = 0; i < N; i++) {
        graph[i].push_back(i);
    }
    for (int i = 0; i < M; i++) {
        int top1, top2;
        cin >> top1 >> top2;

        graph[top1 - 1].push_back(top2 - 1);
        graph[top2 - 1].push_back(top1 - 1);
    }


    for (int i = 0; i < Q; i++) {
        char sign;
        int top1, top2;
        cin >> sign;

        if (sign == '?') {
            cin >> top1 >> top2;
            if (top1 > N or top2 > N) {
                cout << "NO" << "\n";
                continue;
            }

            for (int k = 0; k < N; k++) {
                color[k] = 'W';
            }

            BFS(top1 - 1, top2 - 1);
        }

        if (sign == '-') {
            cin >> top1 >> top2;
            edge_delete(top1 - 1, top2 - 1);
            edge_delete(top2 - 1, top1 - 1);
        }
    }

    return 0;
}