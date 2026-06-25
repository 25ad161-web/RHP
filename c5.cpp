#include <bits/stdc++.h>
using namespace std;

long long maximumValue(vector<vector<int>>& grid) {

    int R = grid.size();
    int C = grid[0].size();

    vector<vector<long long>> dp(R, vector<long long>(C, 0));

    for (int row = 0; row < R; row++) {
        dp[row][0] = grid[row][0];
    }

    for (int col = 1; col < C; col++) {

        for (int row = 0; row < R; row++) {

            long long best = LLONG_MIN;

            for (int prevRow = 0; prevRow < R; prevRow++) {

                if (prevRow != row) { // cannot choose same row
                    best = max(best, dp[prevRow][col - 1]);
                }
            }

            dp[row][col] = best + grid[row][col];
        }
    }

    long long ans = LLONG_MIN;

    for (int row = 0; row < R; row++) {
        ans = max(ans, dp[row][C - 1]);
    }

    return ans;
}

int main() {

    int R, C;

    cout << "Enter rows and columns: ";
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Maximum Value = " << maximumValue(grid);

    return 0;
}
