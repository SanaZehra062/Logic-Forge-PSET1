#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

bool isValid(const string &s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') count++;
        else if (c == ')') {
            count--;
            if (count < 0) return false;
        }
    }
    return count == 0;
}

vector<string> removeInvalidParentheses(string expr) {
    vector<string> res;
    if (expr.empty()) return {""};

    unordered_set<string> visited;
    queue<string> q;
    q.push(expr);
    visited.insert(expr);
    bool found = false;

    while (!q.empty()) {
        string s = q.front(); q.pop();
        if (isValid(s)) {
            res.push_back(s);
            found = true;
        }
        if (found) continue;

        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') continue;
            string t = s.substr(0,i) + s.substr(i+1);
            if (!visited.count(t)) {
                visited.insert(t);
                q.push(t);
            }
        }
    }
    return res;
}

int main() {
    vector<string> testCases = {
        "()())()",
        "(a)())()",
        ")(",
        "()",
        "abc",
        "((("
    };

    for (string expr : testCases) {
        vector<string> ans = removeInvalidParentheses(expr);
        cout << "Input: \"" << expr << "\"" << endl;
        cout << "Output: [";
        for (size_t i = 0; i < ans.size(); i++) {
            cout << "\"" << ans[i] << "\"";
            if (i != ans.size()-1) cout << ", ";
        }
        cout << "]\n\n";
    }

    return 0;
}
