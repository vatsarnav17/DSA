class Solution {
    public:
      long long solve(vector<int>& bt) { 
          long long sum=0,wt=0;
          sort(bt.begin(),bt.end());
          long long n =bt.size();
          for(long long i=1;i<n;i++)
          {
              wt=wt+bt[i-1];
              sum=wt+sum;
          }
          
          return sum/n;
      }
  };