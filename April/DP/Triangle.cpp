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

