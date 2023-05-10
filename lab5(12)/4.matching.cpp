/*
#include <iostream>
#include <vector>

using namespace std;

class kuhn {
    bool DFS(int i, int j, int N, int M, vector<vector<bool>> &matrix, vector<vector<pair<int, int>>> &matching, vector<vector<bool>> &used) {
        if (used[i][j]) {
            return false;
        }

        used[i][j] = true;
        vector<pair<int, int>> neighbors;
        if (j != 0 and !matrix[i][j - 1]) {
            neighbors.emplace_back(i, j - 1);
        }
        if (i != 0 and !matrix[i - 1][j]) {
            neighbors.emplace_back(i - 1, j);
        }
        if (j != (M - 1) and !matrix[i][j + 1]) {
            neighbors.emplace_back(i, j + 1);
        }
        if (i != (N - 1) and !matrix[i + 1][j]) {
            neighbors.emplace_back(i + 1, j);
        }

        for (pair<int, int> x: neighbors) {
            if (matching[x.first][x.second] == pair<int, int>{-1, -1} or DFS(matching[x.first][x.second].first, matching[x.first][x.second].second, N, M, matrix, matching, used)) {
                matching[x.first][x.second] = {i, j};
                return true;
            }
        }
        return false;
    }

public:
    */
/*Идея - на каждом шаге алгоритма мы пытаемся добавить новую вершину в паросочетание, просматривая все возможные
     * пути из этой вершины и пытаясь найти свободную вершину, к которой можно было бы присоединить текущую вершину.*//*

    void kuhn_match(int N, int M, vector<vector<bool>> &matrix) {
        int ans = 0;
        vector<vector<pair<int, int>>> matching(N, vector<pair<int, int>>(M, {-1, -1}));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!matrix[i][j]) {
                    vector<vector<bool>> used(N, vector<bool>(M, false));
                    if (DFS(i, j, N, M, matrix, matching, used)){
                        ans++;
                    };
                }
                */
/*if (matching[i][j] != pair<int, int>{-1, -1}) {
                    ans += 1;
                }*//*

            }
        }
        cout << ans;
        exit(0);
    }
} kuhn_work;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<bool>> matrix(N, vector<bool>(M, false));
    for (int i = 0; i < Q; i++) {
        int top1, top2;
        cin >> top1 >> top2;
        matrix[top1 - 1][top2 - 1] = true;
    }

    kuhn_work.kuhn_match(N, M, matrix);
    return 0;
}*/
