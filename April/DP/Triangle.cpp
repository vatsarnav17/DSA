//MEMOIZATION

class Solution {
    public:
        int f(int row,int idx,vector<vector<int>>&t,vector<vector<int>> &dp)
        {
            int m=t.size();
            int n=t[0].size();
            if(row==m-1)
            {
                return t[row][idx];
            }
            if(dp[row][idx]!=-1)
            {
                return dp[row][idx];
            }
            int d = t[row][idx] + f(row+1,idx,t,dp);
            int dg = t[row][idx] + f(row+1,idx+1,t,dp);
    
            return dp[row][idx] = min(d,dg);
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            int m=triangle.size();
            int n =triangle[0].size();
            vector<vector<int>> dp(m,vector<int>(m,-1));
    
            return f(0,0,triangle,dp);
        }
    };

//TABULATION

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int m = triangle.size();
            vector<vector<int>> dp;
            for (int i = 0; i < m; i++) {
                dp.push_back(vector<int>(triangle[i].size(), 0));
            }
    
            // Initialize last row
            for (int j = 0; j < triangle[m - 1].size(); j++) {
                dp[m - 1][j] = triangle[m - 1][j];
            }
    
            // Bottom-up iteration
            for (int i = m - 2; i >= 0; i--) {
                for (int j = 0; j < triangle[i].size(); j++) {
                    int d = dp[i + 1][j];
                    int dg = dp[i + 1][j + 1];
                    dp[i][j] = triangle[i][j] + min(d, dg);
                }
            }
    
            return dp[0][0];
        }
    };
    