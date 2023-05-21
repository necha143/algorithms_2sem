#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int hash1(string n) {
    int size = n.size();
    int alphabet_size = 45;
    int hash = (int) n[0];

    for (int i = 1; i < size; i++) {
        hash += (int) n[i] * pow(alphabet_size, i);
    }

    return abs(hash % 2000001);
}

int hash2(string n) {
    int size = n.size();
    int alphabet_size = 45;
    int hash = (int) n[0];

    for (int i = 1; i < size; i++) {
        hash += (int) n[i] * pow(alphabet_size, i);
    }

    return abs(hash % (2000000 - 3));
}

void insert(string n, vector<string> &qwe, vector<bool> &ch) {
    int index1 = hash1(n);
    int index2 = hash2(n);

    while (true) {
        if (qwe[index1].empty() and !ch[index1]) {
            qwe[index1] = n;
            ch[index1] = true;
            return;
        } else if (qwe[index2].empty() and !ch[index2]) {
            qwe[index2] = n;
            ch[index2] = true;
            return;
        } else {
            swap(qwe[index1], n);
            index1 = hash1(n);
            index2 = hash2(n);
        }
    }
}

bool contains(const string &n, vector<string> &qwe) {
    int index1 = hash1(n);
    int index2 = hash2(n);

    if (qwe[index1] == n) {
        return true;
    } else if (qwe[index2] == n) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<string> arr1;
    vector<bool> check1;
    arr1 = vector<string>(2000001, "");
    check1 = vector<bool>(2000001, false);
    vector<string> arr2;
    vector<bool> check2;
    arr2 = vector<string>(2000001, "");
    check2 = vector<bool>(2000001, false);

    for (int i = 0; i < N; i++) {
        string task;
        cin >> task;
        if (!contains(task, arr1)){
            insert(task, arr1, check1);
        }
    }

    int res1 = N * 3;
    int res2 = N * 3;
    int res3 = N * 3;
    for (int i = 0; i < N; i++) {
        string task;
        cin >> task;
        if (contains(task, arr1)) {
            res1 -= 2;
            res2 -= 2;
        }
        if (!contains(task, arr2)){
            insert(task, arr2, check2);
        }
    }

    for (int i = 0; i < N; i++) {
        string task;
        cin >> task;
        if (contains(task, arr1) and contains(task, arr2)) {
            res1--;
            res2--;
            res3 -= 3;
        } else if (contains(task, arr1)) {
            res1 -= 2;
            res3 -= 2;
        } else if (contains(task, arr2)) {
            res2 -= 2;
            res3 -= 2;
        }
    }

    if (N == 0) {
        cout << 0 << " " << 0 << " " << 0;
    } else {
        cout << res1 << " " << res2 << " " << res3;
    }
    return 0;
}
