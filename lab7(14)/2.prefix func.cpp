/*
#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string text) {
    int n = (int) text.length();
    vector<int> suf_cnt(n);
    for (int i = 1; i < n; i++) {
        int j = suf_cnt[i - 1];
        while (j > 0 && text[i] != text[j]) {
            j = suf_cnt[j - 1];
        }
        if (text[i] == text[j]) {
            j++;
        }
        suf_cnt[i] = j;
    }
    return suf_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string text;
    cin >> text;

    vector<int> ans = prefix_function(text);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}*/
