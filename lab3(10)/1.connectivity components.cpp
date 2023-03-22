#include <iostream>
#include <vector>

using namespace std;


int n, m, numComponents = 0;
vector<vector<int>> arr;
vector<int> mark;
vector<bool> trap;
vector<bool> safe_comp;

void DFS(int i) {
    mark[i] = numComponents + 1;
    if (!arr[i].empty()) {
        for (int &j: arr[i]) {
            if (mark[j] == 0) {
                DFS(j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    arr.resize(n, vector<int>(0));
    mark.resize(n, 0);
    trap.resize(n, false);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr[temp1 - 1].push_back(temp2 - 1);
        arr[temp2 - 1].push_back(temp1 - 1);
    }

    for (int i = 0; i < n; i++) {
        int joker;
        cin >> joker;
        if (joker == 1) {
            trap[i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) {
            DFS(i);
            numComponents++;
        }
    }

    cout << numComponents << "\n";
    for (int i = 0; i < n; i++) {
        cout << mark[i] << " ";
    }
    cout << "\n";

    safe_comp.resize(numComponents, true);
    for (int i = 0; i < n; i++) {
        if (trap[i]) {
            safe_comp[mark[i] - 1] = false;
        }
    }

    for (int i = 0; i < numComponents; i++) {
        safe_comp[i] ? cout << "0" : cout << "1";
        cout << " ";
    }

    return 0;
}