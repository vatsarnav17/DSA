//MEMOIZATION

class Solution {
    public:
    
        int f(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &OG) {
            if (m == 0 && n == 0) {
                return (OG[0][0] == 0) ? 1 : 0; 
            }
            if (m < 0 || n < 0 || OG[m][n] != 0) {
                return 0;
            }
            if (dp[m][n] != -1) {
                return dp[m][n];
            }
    
            int up = f(m - 1, n, dp, OG);
            int left = f(m, n - 1, dp, OG);
    
            return dp[m][n] = up + left;
        }
    
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
    
            if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
                return 0;
            }
    
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return f(m - 1, n - 1, dp, obstacleGrid);
        }
    };
    