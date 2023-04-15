#include <iostream>

using namespace std;

void floyd_warshall(int **arr, int N) {
    int diametr = 0;
    for (int i = 0; i < N; i++) {
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                if (arr[u][i] == INT_MAX or arr[i][v] == INT_MAX) {
                    continue;
                }
                arr[u][v] = min(arr[u][v], arr[u][i] + arr[i][v]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] > diametr and arr[i][j] < INT_MAX) {
                diametr = arr[i][j];
            }
        }
    }
    cout << diametr;
}

int main() {
    int N, M;
    cin >> N >> M;

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
        arr[top2 - 1][top1 - 1] = weight;
    }

    floyd_warshall(arr, N);
    return 0;
}