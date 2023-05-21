#include <iostream>
#include <vector>

using namespace std;

int chairs(int N, vector<int> &plus, vector<int> &minus) {
    int cnt = 0;
    int elem;

    for (int i = 0; i < N; i++) {
        cin >> elem;

        if (elem - i >= 0) {
            cnt += plus[elem - i];
            plus[elem - i]++;
        } else {
            cnt += minus[abs(elem - i)];
            minus[abs(elem - i)]++;
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> plus;
    vector<int> minus;
    plus.reserve(999999);
    minus.reserve(999999);
    for (int i = 0; i < 999999; i++) {
        plus.push_back(0);
        minus.push_back(0);
    }

    cout << chairs(N, plus, minus);
    return 0;
}
