#include <iostream>
#include <vector>

using namespace std;

void repetitions(int N, int M, string text) {
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        int ind_1, ind_2, size;
        cin >> ind_1 >> ind_2 >> size;
        if (text.substr(ind_1 - 1, size) == text.substr(ind_2 - 1, size)) {
            cnt++;
        }
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string text;
    cin >> text;

    repetitions(N, M, text);
    return 0;
}
