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

    vector<int> impact(n);

    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                product *= contributions[j];
            }
        }
        impact[i] = product;
    }

    cout << "Impact array:\n";
    for (int i = 0; i < n; i++) {
        cout << impact[i] << " ";
    }

    return 0;
}

