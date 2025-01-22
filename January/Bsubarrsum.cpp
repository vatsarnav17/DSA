class Solution {
public:
    int Calculate(vector<int>& nums, int target) 
    {
        int front=0;
        int end=0;
        int count=0;
        int sum =0;
        if(target<0){
        return 0;
        }
        for(int i =0;i<nums.size();i++)
        {
            sum=sum+nums[end];
            while(sum>target){
                sum=sum-nums[front];
                front++;
            } 
            count = count + end-front+1;   
            end++;
        }
       return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int target) 
    {
    return Calculate(nums,target)-Calculate(nums,target-1);   
    }
};