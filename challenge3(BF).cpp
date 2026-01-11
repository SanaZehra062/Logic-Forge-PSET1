#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Enter size of Team A scores: ";
    cin >> m;
    cout << "Enter size of Team B scores: ";
    cin >> n;

    vector<int> A(m), B(n);
    cout << "Enter sorted scores of Team A:\n";
    for (int i = 0; i < m; i++)
        cin >> A[i];

    cout << "Enter sorted scores of Team B:\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    vector<int> merged;
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (A[i] <= B[j])
            merged.push_back(A[i++]);
        else
            merged.push_back(B[j++]);
    }

    while (i < m) merged.push_back(A[i++]);
    while (j < n) merged.push_back(B[j++]);

    int total = merged.size();
    double median;

    if (total % 2 == 0)
        median = (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    else
        median = merged[total / 2];

    cout << "Median score: " << median << endl;
    return 0;
}
