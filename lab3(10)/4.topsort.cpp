#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> result;
vector<bool> color;
bool cycle = false;

void dfs(int v) {
    color[v] = true;
    for (int to: graph[v]) {
        if (!color[to]) {
            dfs(to);
        }
    }

    result.push_back(v);
}

void topsort() {
    for (int i = 1; i < graph.size(); i++) {
        color[i] = false;
    }

    result.clear();
    for (int i = 1; i < graph.size(); i++) {
        if (!color[i]) {
            dfs(i);
        }
    }
    std::reverse(result.begin(), result.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    color.resize(n + 1);
    result.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
    }

    topsort();
    int ans[n];
    for (int i=0; i<n; i++){
        ans[result[i]]=i+1;
    }

    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}