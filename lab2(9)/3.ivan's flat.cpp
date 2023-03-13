#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct One {
    char space;
    int amount;
};
vector<vector<One>> home;
vector<vector<int>> adj;
vector<char> color;


void BFS(int start) {
    queue<int> Q;
    Q.push(start);
    color[start] = 'B';

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v: adj[u]) {
            if (color[v] == 'W') {
                color[v] = 'B';
                Q.push(v);
            }
        }
    }
}


void Bypass(int n, int m, int cnt) {
    adj.resize(cnt, vector<int>());

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (home[i][j].space == '.') {
                if (home[i - 1][j].space == '.') {
                    adj[home[i][j].amount].push_back(home[i - 1][j].amount);
                }
                if (home[i + 1][j].space == '.') {
                    adj[home[i][j].amount].push_back(home[i + 1][j].amount);
                }
                if (home[i][j - 1].space == '.') {
                    adj[home[i][j].amount].push_back(home[i][j - 1].amount);
                }
                if (home[i][j + 1].space == '.') {
                    adj[home[i][j].amount].push_back(home[i][j + 1].amount);
                }
            }
        }
    }

    int cur = 0;
    color.resize(cnt, 'W');
    for (int i = 0; i != adj.size(); i++) {
        if (color[i] == 'W') {
            BFS(i);
            cur++;
        }
    }
    cout << cur;
    exit(0);
}


int main() {
    int n, m;
    cin >> n >> m;

    home.resize(n, vector<One>());
    int cnt_of_freedom = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            One *place = new One();
            cin >> place->space;
            if (place->space == '.') {
                place->amount = cnt_of_freedom++;
            }
            home[i].push_back(*place);
        }
    }

    Bypass(n, m, cnt_of_freedom);
    return 0;
}
