class Solution {
public:
    bool findsubsum(int ind,int target ,vector<int>& vec , vector<vector<int>> &dp)
    {
        if(target==0)
        {
            return true;
        }
        if(ind==0)
        {
            return(target==vec[ind]);
        }
        
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }

        bool nt = findsubsum(ind-1,target,vec,dp);
        bool take = false;
        if(target>=vec[ind])
        {
            take = findsubsum(ind-1,target-vec[ind],vec,dp);
        }
        
        return dp[ind][target] = take || nt ;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        if(sum%2 != 0)
        {
            return false;
        }
        int tsum = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(tsum+1,-1));
        return findsubsum(nums.size()-1,tsum,nums,dp);
    }
};