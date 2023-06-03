/*
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Poker {
    bool isPalindrome(int M, vector<int> &cards) {
        bool palindrome = true;
        for (int i = 0; i < M; i++) {
            if (cards[i] != cards[M * 2 - i - 1]) {
                palindrome = false;
                break;
            }
        }
        return palindrome;
    }

public:
    static vector<int> initialize(int N) {
        vector<int> cards;
        for (int i = 0; i < N; i++) {
            int card;
            cin >> card;
            cards.push_back(card);
        }
        return cards;
    }

    void amount_of_cards(int N, vector<int> &all_cards) {
        vector<int> res;
        for (int i = 0; i <= N / 2; i++) {
            if (isPalindrome(i, all_cards)) {
                res.push_back(all_cards.size() - i);
            }
        }

        reverse(res.begin(), res.end());
        for (int re: res) {
            cout << re << " ";
        }

        exit(0);
    }
} poker;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> all_cards = Poker::initialize(N);
    poker.amount_of_cards(N, all_cards);

    return 0;
}*/
