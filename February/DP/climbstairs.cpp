//MEMOIZATION - TOPDOWN

class Solution {
    public:
        int help(int n,vector<int>& dp)
        {
            if(n==1||n==0)
            {
                return 1;
            }
            if(dp[n]!=-1) return dp[n];
            
            return dp[n] = help(n-1,dp)+help(n-2,dp);
        }
        int climbStairs(int n) {
            vector<int> dp(n+1,-1);
            return help(n,dp);
        }
};

//TABULATION - BOTTOM UP


class Solution {
    public:
        int climbStairs(int n) {
            if(n==1) return 1;
    
            vector<int> dp(n+1);
            dp[0]=1;
            dp[1]=1;
    
            for(int i=2;i<=n;i++)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
    
            return dp[n];
        }
};

//FIBBONACCI

class Solution {
    public:
        int climbStairs(int n) {
            if(n==1) return 1;
    
            int prev1=1;
            int prev2=1;
            int curr;
            for(int i=2;i<=n;i++)
            {
                curr=prev1+prev2;
                prev2=prev1;
                prev1=curr;
            }
    
            return prev1;
        }
    };
