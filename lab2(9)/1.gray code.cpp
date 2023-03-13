#include <iostream> // https://ru.wikipedia.org/wiki/Код_Грея
#include <math.h>
using namespace std;

int gray(int n, int *m, int depth) {
    int i, t = (1 << (depth - 1));

    if (depth == 0) {
        m[0] = 0;
    } else {
        for (i = 0; i < t; i++) {
            m[t + i] = m[t - i - 1] + (1 << (depth - 1));
        }
    }
    if (depth != n) {
        gray(n, m, depth + 1);
    }

    return 0;
}

void tenTotwo(int x, int n) {
    long long bin = 0;
    for (int j = 0; x > 0; j++) {
        bin += (x % 2) * pow(10, j);
        x /= 2;
        n--;
    }

    if (n != 0) {
        while (n--) cout << 0;
    }
    if (bin == 0) {
        cout << endl;
        return;
    }
    cout << bin << endl;
}

int main() {
    int n;
    cin >> n;
    int amount = pow(2, n);
    int arr[amount];
    int depth = 0;
    gray(n, arr, depth);

    for (int i = 0; i < amount; i++) {
        tenTotwo(arr[i], n);
    }

    return 0;
}
