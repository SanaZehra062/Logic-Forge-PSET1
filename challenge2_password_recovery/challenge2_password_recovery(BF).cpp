#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isValid(string window, string pattern) {
    unordered_map<char, int> freq;
    for (char c : window)
        freq[c]++;

    for (char c : pattern) {
        if (freq[c] == 0)
            return false;
        freq[c]--;
    }
    return true;
}

int main() {
    string log, pattern;
    cout << "Enter log string: ";
    cin >> log;
    cout << "Enter pattern string: ";
    cin >> pattern;

    string ans = "";
    int minLen = log.length() + 1;

    for (int i = 0; i < log.length(); i++) {
        for (int j = i; j < log.length(); j++) {
            string sub = log.substr(i, j - i + 1);
            if (isValid(sub, pattern)) {
                if (sub.length() < minLen) {
                    minLen = sub.length();
                    ans = sub;
                }
            }
        }
    }

    cout << "Minimum window: " << ans << endl;
    return 0;
}
