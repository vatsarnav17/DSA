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