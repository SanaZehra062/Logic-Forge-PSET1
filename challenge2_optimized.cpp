#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string log, pattern;
    cout << "Enter log string: ";
    cin >> log;
    cout << "Enter pattern string: ";
    cin >> pattern;

    unordered_map<char, int> need;
    for (char c : pattern)
        need[c]++;

    int required = pattern.length();
    int left = 0, minLen = log.length() + 1, start = 0;

    for (int right = 0; right < log.length(); right++) {
        if (need[log[right]] > 0)
            required--;
        need[log[right]]--;

        while (required == 0) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            need[log[left]]++;
            if (need[log[left]] > 0)
                required++;
            left++;
        }
    }

    if (minLen > log.length())
        cout << "Minimum window: " << "" << endl;
    else
        cout << "Minimum window: " << log.substr(start, minLen) << endl;

    return 0;
}
