#include <iostream>
#include <vector>
#include <stack>

using namespace std;


void edge_delete(int top1, int top2, vector<vector<int>> &graph) {
    int ind = 0;
    while (graph[top1][ind] != top2) {
        ind++;
    }
    graph[top1].erase(graph[top1].begin() + ind);
}

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

void SNM(vector<vector<int>> &graph, int n, vector<int> &rank, vector<int> &parent) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            union_Sets(i, graph[i][j], rank, parent);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n);
    vector<int> parent;
    vector<int> rank;

    for (int i = 0; i < n; i++) {
        graph[i].push_back(i);
        parent.push_back(i);
        rank.push_back(1);
    }

    for (int i = 0; i < m; i++) {
        int top1, top2;
        cin >> top1 >> top2;
        graph[top1 - 1].push_back(top2 - 1);
        graph[top2 - 1].push_back(top1 - 1);
    }

    stack<vector<int>> request;
    for (int i = 0; i < q; i++) {
        char sign;
        int top1, top2;
        cin >> sign;
        int numb_sign = 0;
        cin >> top1 >> top2;

        if (sign == '-') {
            numb_sign = 1;
            edge_delete(top1 - 1, top2 - 1, graph);
            edge_delete(top2 - 1, top1 - 1, graph);
            /*unionSets(top1 - 1, top2 - 1, rank);*/
        }

        request.push({numb_sign, top1 - 1, top2 - 1});
    }

    SNM(graph, n, rank, parent);
    stack<string> ans;
    while (!request.empty()) {
        vector<int> req = request.top();
        request.pop();
        if (req[0] == 0) {
            if (req[1] > n or req[2] > n) {
                cout << "NO" << "\n";
                continue;
            }

            string what = find_Set(req[1], parent) == find_Set(req[2], parent) ? "YES" : "NO";
            ans.push(what);

        } else {
            union_Sets(req[1], req[2], rank, parent);
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << "\n";
        ans.pop();
    }
    return 0;
}