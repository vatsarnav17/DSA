class Solution {
    public:
        int rob(vector<int>& inhouse)
        {
            vector<int>temp1,temp2;
            int n=inhouse.size();
            if(n==1) return inhouse[0];
            for(int i=0;i<n;i++)
            {
                if(i!=0) temp1.push_back(inhouse[i]);
                if(i!=n-1) temp2.push_back(inhouse[i]);
            }
            return max(houserob(temp1),houserob(temp2));
        }
        int houserob(vector<int>& nums) {
            int n = nums.size();
            int prev=nums[0];
            int prev2 = 0;
            for(int i=1;i<n;i++)
            {
                int take = nums[i];
                if(i>1)
                {
                    take+=prev2;
                }
                int not_taken = prev;
                int curri = max(take,not_taken);
                prev2=prev;
                prev=curri;
            }
            return prev;
        }
    };