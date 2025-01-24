class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return calc(nums,k)-calc(nums,k-1);       
    }
    int calc(vector<int>& nums,int k)
    {
        int l=0,r=0,count=0;
        map<int,int> mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count=count+ (r-l+1);
            r++;
        }
        return count; 
    }
};