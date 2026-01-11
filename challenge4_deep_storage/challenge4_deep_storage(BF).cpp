#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthSmallestBrute(vector<vector<int>>& matrix, int k) {
    vector<int> nums;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nums.push_back(matrix[i][j]);
    sort(nums.begin(), nums.end());
    return nums[k-1];
}

int main() {
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    cout << kthSmallestBrute(matrix, k) << endl;
    return 0;
}
