#include <bits/stdc++.h>
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

void dfs(const string &s, int index, int leftRem, int rightRem, string path, unordered_set<string> &res) {
    if (index == s.size()) {
        if (leftRem == 0 && rightRem == 0 && isValid(path))
            res.insert(path);
        return;
    }

    char c = s[index];
    if (c == '(' && leftRem > 0) {
        dfs(s, index+1, leftRem-1, rightRem, path, res);
    } else if (c == ')' && rightRem > 0) {
        dfs(s, index+1, leftRem, rightRem-1, path, res);
    }

    path.push_back(c);
    if (c != '(' && c != ')') {
        dfs(s, index+1, leftRem, rightRem, path, res);
    } else if (c == '(') {
        dfs(s, index+1, leftRem, rightRem, path, res);
    } else if (c == ')') {
        dfs(s, index+1, leftRem, rightRem, path, res);
    }
}

vector<string> removeInvalidParenthesesBrute(string s) {
    int leftRem = 0, rightRem = 0;
    for (char c : s) {
        if (c == '(') leftRem++;
        else if (c == ')') {
            if (leftRem > 0) leftRem--;
            else rightRem++;
        }
    }

    unordered_set<string> res;
    dfs(s, 0, leftRem, rightRem, "", res);
    return vector<string>(res.begin(), res.end());
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
        vector<string> ans = removeInvalidParenthesesBrute(expr);
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
