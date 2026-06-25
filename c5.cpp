class Solution {
public:

    vector<long long> getFMax(vector<vector<long long>>& dp, int col, int R) {

        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;

        for(int row = 0; row < R; row++) {

            if(dp[row][col] > max1) {
                max2 = max1;
                max1 = dp[row][col];
            }
            else if(dp[row][col] > max2) {
                max2 = dp[row][col];
            }
        }

        return {max1, max2};
    }

    long long maximumValue(vector<vector<int>>& grid) {

        int R = grid.size();
        int C = grid[0].size();

        vector<vector<long long>> dp(R, vector<long long>(C, 0));

        // First column
        for(int row = 0; row < R; row++) {
            dp[row][0] = grid[row][0];
        }

        // Remaining columns
        for(int col = 1; col < C; col++) {

            vector<long long> fmax = getFMax(dp, col - 1, R);

            for(int row = 0; row < R; row++) {

                if(dp[row][col - 1] == fmax[0])
                    dp[row][col] = fmax[1] + grid[row][col];
                else
                    dp[row][col] = fmax[0] + grid[row][col];
            }
        }

        long long ans = LLONG_MIN;

        for(int row = 0; row < R; row++) {
            ans = max(ans, dp[row][C - 1]);
        }

        return ans;
    }
};