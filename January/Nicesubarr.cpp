class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return calculate(nums,k)-calculate(nums,k-1);
    }
    int calculate(vector<int>& nums, int k)
    {
        int l=0,r=0,count=0,sum=0;
        if(k<0){
            return 0;
        }
        while(r<nums.size())
        {
            sum = sum+(nums[r]%2);
            while(sum>k)
            {
                sum = sum - (nums[l]%2);
                l++;
            }
            count=count+r-l+1;
            r++;
        }
        return count;
    }
};