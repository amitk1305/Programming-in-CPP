class Solution {
 public:
     int uniquePaths(int m, int n) {
         vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
         return helper(m, n, dp);
     }

 private:
     int helper(int m, int n, vector<vector<int>>& dp) {
         if (m == 1 && n == 1) return 1;
         if (m < 1 || n < 1) return 0;
         if (dp[m][n] != -1) return dp[m][n];

         int count = 0;
         count += helper(m - 1, n, dp);
         count += helper(m, n - 1, dp);

         return dp[m][n] = count;
     }
 };