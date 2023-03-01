#include <iostream>
#include <cmath>

using namespace std;

int maxPow(int length) {
    int myPow = 0;
    while (pow(2, myPow) < length) {
        ++myPow;
    }
    return myPow;
}

bool isDegreeOfTwo(int x) {
    bool res = true;
    while (x > 0) {
        if (x == 1) {
            return res;
        } else if (x % 2 != 0) {
            return false;
        }
        x /= 2;
    }
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        string str;
        cin >> str;
        int strPow = maxPow(str.length());
        int bitArr[strPow];
        for (int i = 0; i < strPow; i++) {
            bitArr[i] = 0;
        }
        int index = 0;
        int step = 1;
        while (step < pow(2, strPow)) {
            int stepControl = 0;
            for (int i = step - 1; i < str.length(); i++) {
                if (str[i] == '1') {
                    bitArr[index]++;
                }
                stepControl++;
                if (stepControl == step) {
                    stepControl = 0;
                    i += step;
                }
            }
            step += step;
            index++;
        }
        int mistake = 0;
        for (int i = 0; i < strPow; i++) {
            if (bitArr[i] % 2 == 1) {
                mistake += pow(2, i);
            }
        }
        if (mistake) {
            str[mistake - 1] = str[mistake - 1] == '1' ? '0' : '1';
        }
        string myStr = "";
        for (int i = 0; i < str.length(); i++) {
            if (!isDegreeOfTwo(i + 1)) {
                myStr.push_back(str[i]);
            }
        }
        cout << myStr << endl;
    }
}
