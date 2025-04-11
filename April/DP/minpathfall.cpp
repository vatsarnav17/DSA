//MEMOIZATION 

class Solution {
    public:
        int f(int row,int idx,vector<vector<int>>&mat,vector<vector<int>>&dp)
        {
            int m=mat.size();
            if(idx<0 || idx>=m)
            {
                return 1e9;
            }
            if(row==m-1)
            {
                return dp[row][idx] = mat[row][idx];
            }
            if(dp[row][idx]!=-1)
            {
                return dp[row][idx];
            }
            int s = mat[row][idx] + f(row+1,idx,mat,dp);
            int l = mat[row][idx] + f(row+1,idx-1,mat,dp);
            int r = mat[row][idx] + f(row+1,idx+1,mat,dp);
    
            return dp[row][idx] = min(s,min(l,r));
        }
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int m=matrix.size();
            int res = 1e9;
            vector<vector<int>>dp(m,vector<int>(m,-1));
            for(int i=0;i<m;i++)
            {
                res=min(res,f(0,i,matrix,dp));
            }
            return res;
        }
    };

    //TABULATION

    class Solution {
        public:
            int minFallingPathSum(vector<vector<int>>& matrix) {
                int n = matrix.size();
                vector<vector<int>> dp(n, vector<int>(n, 0));
        
                // Base case: last row is the same as matrix
                for (int col = 0; col < n; ++col) {
                    dp[n - 1][col] = matrix[n - 1][col];
                }
        
                // Bottom-up DP
                for (int row = n - 2; row >= 0; --row) {
                    for (int col = 0; col < n; ++col) {
                        int down = dp[row + 1][col];
                        int leftDiag = (col > 0) ? dp[row + 1][col - 1] : 1e9;
                        int rightDiag = (col < n - 1) ? dp[row + 1][col + 1] : 1e9;
        
                        dp[row][col] = matrix[row][col] + min({down, leftDiag, rightDiag});
                    }
                }
        
                // Find the minimum in the first row
                int res = 1e9;
                for (int col = 0; col < n; ++col) {
                    res = min(res, dp[0][col]);
                }
        
                return res;
            }
        };
        