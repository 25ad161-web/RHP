#include <bits/stdc++.h>
using namespace std;

long long maximumValue(vector<vector<int>>& grid) {

    int R = grid.size();
    int C = grid[0].size();

    vector<vector<long long>> dp(R, vector<long long>(C, 0));

   
    for (int col = 0; col < C; col++) {
        dp[0][col] = grid[0][col];
    }

   
    for (int row = 1; row < R; row++) {

        for (int col = 0; col < C; col++) {

            long long best = LLONG_MIN;

            for (int prevCol = 0; prevCol < C; prevCol++) {

                if (prevCol != col) { 
                    best = max(best, dp[row - 1][prevCol]);
                }
            }

            dp[row][col] = best + grid[row][col];
        }
    }

    long long ans = LLONG_MIN;

    for (int col = 0; col < C; col++) {
        ans = max(ans, dp[R - 1][col]);
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
