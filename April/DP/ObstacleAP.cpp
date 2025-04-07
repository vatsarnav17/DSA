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
    
//TABULATION

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& OG) {
            int m=OG.size();
            int n=OG[0].size();
            vector<vector<int>> dp(m,vector<int>(n));
    
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int up=0,left=0;
                    if(OG[i][j]!=0)
                    {
                        dp[i][j]=0;
                    }
                    else if(i == 0 && j==0 )
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        if(i>0){
                            up=dp[i-1][j];
                        }
                        if(j>0){
                            left = dp[i][j-1];
                        }
                        dp[i][j]=up+left;
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };