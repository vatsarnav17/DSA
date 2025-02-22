// MEMOIZATION TOPDOWN

class Solution {
    public:
      int f(int ind,vector<int>& height,vector<int>& dp)
      {
          if(ind==0)
          {
              return 0;
          }
          if(dp[ind]!=-1)
          {
              return dp[ind];
          }
          int left = f(ind-1,height,dp) + abs(height[ind]-height[ind-1]);
          int right = INT_MAX;
          if(ind>1)
          {
              right = f(ind-2,height,dp) + abs(height[ind]-height[ind-2]);
          }
          return dp[ind]=min(left,right);
      }
      int minCost(vector<int>& height) {
          int n = height.size();
          vector<int> dp(n+1,-1);
          return f(n-1,height,dp);
      }
  };

//TABULATION BOTTOMUP

class Solution {
    public:
      int minCost(vector<int>& height) {
          int n=height.size();
          vector<int> dp(n,0);
          dp[0]=0;
          for(int i=1;i<n;i++)
          {
              int fs=dp[i-1]+abs(height[i-1]=height[i]);
              int ss=INT_MAX;
              if(i>1)
              {
                  ss=dp[i-2]+ abs(height[i-2]-height[i]);
              }
              dp[i]=min(fs,ss);
          }
          return dp[n-1];
      }
  };

//MOST OPTIMAL

class Solution {
    public:
      int minCost(vector<int>& height) {
          int n=height.size();
          vector<int> dp(n,0);
          dp[0]=0;
          for(int i=1;i<n;i++)
          {
              int fs=dp[i-1]+abs(height[i-1]=height[i]);
              int ss=INT_MAX;
              if(i>1)
              {
                  ss=dp[i-2]+ abs(height[i-2]-height[i]);
              }
              dp[i]=min(fs,ss);
          }
          return dp[n-1];
      }
  };