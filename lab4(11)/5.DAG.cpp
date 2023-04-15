#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void top_sort_dfs(int v, int **arr, int n, bool *visited, stack<int> &TS) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            top_sort_dfs(i, arr, n, visited, TS);
        }
    }
    TS.push(v);
}

int relax(int **arr, int N, stack<int> TS, int *distance, int T) {
    while (!TS.empty()) {
        int v = TS.top();
        if (distance[v] != INT_MAX) {
            for (int i = 0; i < N; i++) {
                if (arr[v][i] != INT_MAX) {
                    if (distance[v] + arr[v][i] < distance[i]) {
                        distance[i] = distance[v] + arr[v][i];
                    }
                }
            }
        }
        TS.pop();
    }

    return distance[T];
}

void DAG(int **arr, int N, int S, int T) {
    stack<int> TS;
    bool visited[N + 1];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }

    top_sort_dfs(S, arr, N, visited, TS);

    int Distance[N];
    for (int i = 0; i < N; i++) {
        Distance[i] = INT_MAX;
    }
    Distance[S] = 0;

    int destination = relax(arr, N, TS, Distance, T);

    if (destination != INT_MAX) {
        cout << destination;
    } else {
        cout << "-1";
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    int S, T;
    cin >> S >> T;
    S--;
    T--;

    int **arr = new int *[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                arr[i][j] = 0;
            } else {
                arr[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int top1, top2, weight;
        cin >> top1 >> top2 >> weight;
        arr[top1 - 1][top2 - 1] = weight;
    }

    DAG(arr, N, S, T);
    return 0;
}