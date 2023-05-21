#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val = 0;
};

int my_hash(int i, int numb) {
    return numb % 99999 + i;
}

void insert(node *table, int numb) {
    int index = my_hash(0, numb);

    for (int i = 0; i < 99999 - 1; i++) {
        if (table[index].val == 0) {
            table[index].val = numb;
            return;
        }
        index = my_hash(i, numb);
    }
}

bool contains(node *table, int numb) {
    int index = my_hash(0, numb);

    for (int i = 0; i < 99999 - 1; i++) {
        if (table[index].val == numb) {
            return true;
        } else if (table[index].val == 0) {
            return false;
        }
        index = my_hash(i, numb);
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    node *table_x = new node[99999];
    node *table_y = new node[99999];

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if (!contains(table_x, x) and !contains(table_y, y)) {
            cnt++;
            if (cnt < 4) {
                insert(table_x, x);
                insert(table_y, y);
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    cnt == 3 ? cout << "YES" : cout << "NO";
    return 0;
}
