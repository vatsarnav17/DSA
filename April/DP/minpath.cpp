//MEMOIZATOIN 

class Solution {
    public:
        int f(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp)
        {
            if(m==0 && n==0)
            {
                return grid[m][n];
            }
            if(m<0 || n<0)
            {
                return 1e9 ;
            }
            if(dp[m][n]!=-1)
            {
                return dp[m][n];
            }
            int up = grid[m][n] + f(m-1,n,grid,dp);
            int left = grid[m][n] + f(m,n-1,grid,dp);
    
            return dp[m][n] = min(up,left);
        }
        int minPathSum(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<int>> dp(m,vector<int>(n,-1));
            return f(m-1,n-1,grid,dp);
        }
    };
 
//TABULATION

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
    
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == 0 && j == 0) {
                        dp[i][j] = grid[i][j];
                    } else {
                        int up = i > 0 ? dp[i-1][j] : INT_MAX;
                        int left = j > 0 ? dp[i][j-1] : INT_MAX;
                        dp[i][j] = grid[i][j] + min(up, left);
                    }
                }
            }
    
            return dp[m-1][n-1];
        }
    };
    