class Solution {
public:

    vector<long long> getFMax(vector<vector<long long>>& dp, int row, int C) {

        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;

        for (int col = 0; col < C; col++) {

            if (dp[row][col] > max1) {
                max2 = max1;
                max1 = dp[row][col];
            }
            else if (dp[row][col] > max2) {
                max2 = dp[row][col];
            }
        }

        return {max1, max2};
    }

    long long maximumValue(vector<vector<int>>& grid) {

        int R = grid.size();
        int C = grid[0].size();

        vector<vector<long long>> dp(R, vector<long long>(C, 0));

        // First row
        for (int col = 0; col < C; col++) {
            dp[0][col] = grid[0][col];
        }

        // Remaining rows
        for (int row = 1; row < R; row++) {

            vector<long long> fmax = getFMax(dp, row - 1, C);

            for (int col = 0; col < C; col++) {

                if (dp[row - 1][col] == fmax[0])
                    dp[row][col] = fmax[1] + grid[row][col];
                else
                    dp[row][col] = fmax[0] + grid[row][col];
            }
        }

        long long ans = 0;

        for (int col = 0; col < C; col++) {
            ans = max(ans, dp[R - 1][col]);
        }

        return ans;
    }
};