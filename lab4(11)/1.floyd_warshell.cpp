#include <iostream>

using namespace std;

void floyd_warshall(int **arr, int N, int K) {
    for (int i = 0; i < N; i++) {
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                if (abs(u - i) > K or abs(v - i) > K) {
                    continue;
                }
                if (arr[u][i] == INT_MAX or arr[i][v] == INT_MAX) {
                    continue;
                }
                arr[u][v] = min(arr[u][v], arr[u][i] + arr[i][v]);
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int top1, top2;
        cin >> top1 >> top2;
        if (arr[top1 - 1][top2 - 1] == INT_MAX) {
            cout << "-1" << "\n";
        } else {
            cout << arr[top1 - 1][top2 - 1] << "\n";
        }
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int **arr = new int *[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < M; i++) {
        int top1, top2, weight;
        cin >> top1 >> top2 >> weight;
        arr[top1 - 1][top2 - 1] = weight;
    }

    floyd_warshall(arr, N, K);
    return 0;
}