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

    int total = m + n;
    int mid1 = (total - 1) / 2;
    int mid2 = total / 2;

    int i = 0, j = 0, count = 0;
    int curr = 0, prev = 0;

    while (count <= mid2) {
        prev = curr;

        if (i < m && (j >= n || A[i] <= B[j])) {
            curr = A[i++];
        } else {
            curr = B[j++];
        }
        count++;
    }

    double median;
    if (total % 2 == 0)
        median = (prev + curr) / 2.0;
    else
        median = curr;

    cout << "Median score: " << median << endl;
    return 0;
}
