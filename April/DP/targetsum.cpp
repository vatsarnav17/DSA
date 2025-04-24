class Solution {
    public:
      int f(int ind,int target,vector<int>&arr,vector<vector<int>>&dp)
      {
          if(target == 0){
              return true;
          }
          if(ind == 0)
              return target == arr[0];
          if(dp[ind][target]!=-1){
              return dp[ind][target];
          }    
          bool nottake = f(ind-1,target,arr,dp);
          bool take = false;
          if(target >= arr[ind]){
              take = f(ind-1,target-arr[ind],arr,dp);
          }
          return dp[ind][target] = take || nottake;
      }
  
      bool isSubsetSum(vector<int>arr, int target){
          int n=arr.size();
          vector<vector<int>> dp(n,vector<int>(target+1,-1));
          return f(n-1,target,arr,dp);
      }
  
  };