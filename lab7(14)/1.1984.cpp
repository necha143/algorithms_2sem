#include <iostream>
#include <vector>

using namespace std;

void findNameReferences(string name, string text, vector<int> &references) {
    int nameLength = name.length();
    int textLength = text.length();
    bool check;

    for (int i = 0; i <= textLength; i++) {
        check = false;
        for (int j = 0; j < nameLength; j++) {
            if (text[i + j] == name[j]) {
                check = true;
            } else {
                check = false;
                break;
            }
        }

        if (check) {
            references.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string text;
    string name;
    cin >> text >> name;

    vector<int> references;
    findNameReferences(name, text, references);

    cout << references.size() << "\n";
    for (int i = 0; i < references.size(); i++) {
        cout << references[i] << " ";
    }

    return 0;
}
