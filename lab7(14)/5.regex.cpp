/*
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class RegexMatch {
    static bool checkCorrect(vector<string> &person_info) {
        if (person_info.size() != 8) {
            return false;
        }

        regex fio("^([A-Z])([a-z]*)$");
        if (!regex_match(person_info[0], fio) or !regex_match(person_info[1], fio) or
            !regex_match(person_info[2], fio)) {
            return false;
        }

        regex age("^[0-9]{2}$");
        if (!regex_match(person_info[3], age)) {
            return false;
        }

        regex phone_number(R"(^((8|\+7)[\- ]?)?(\(?\d{3}\)?[\- ]?)?[\d\- ]{7,10}$)");
        if (!regex_match(person_info[4], phone_number)) {
            return false;
        }

        regex city("^(g.)[A-Z][A-Z][A-Z]$");
        regex street("^(ul.)[A-Z]([a-z]*)$");
        regex house("^(d.)([0-9]+)$");
        if (!regex_match(person_info[5], city) or !regex_match(person_info[6], street) or
            !regex_match(person_info[7], house)) {
            return false;
        }

        return true;
    }

public:
    static void check_match(int M) {
        string wtf;
        getline(cin, wtf);

        for (int i = 0; i < M; i++) {
            string person;
            getline(cin, person);

            vector<string> person_info = {};
            string info = {};
            for (char c: person) {
                if (c != ' ' and c != ',') {
                    info.push_back(c);
                } else if (!info.empty()) {
                    person_info.push_back(info);
                    info = {};
                }
            }
            person_info.push_back(info);

            checkCorrect(person_info) ? cout << "YES" << "\n" : cout << "NO" << "\n";
        }

        exit(0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M;
    cin >> M;

    RegexMatch::check_match(M);
    return 0;
}*/
