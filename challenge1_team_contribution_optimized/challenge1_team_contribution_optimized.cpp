#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of team members: ";
    cin >> n;

    vector<int> contributions(n);
    cout << "Enter contribution scores:\n";
    for (int i = 0; i < n; i++) {
        cin >> contributions[i];
    }

    vector<int> impact(n, 1);

    int leftProduct = 1;
    for (int i = 0; i < n; i++) {
        impact[i] = leftProduct;
        leftProduct *= contributions[i];
    }

    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        impact[i] *= rightProduct;
        rightProduct *= contributions[i];
    }

    cout << "Impact array:\n";
    for (int i = 0; i < n; i++) {
        cout << impact[i] << " ";
    }

    return 0;
}
