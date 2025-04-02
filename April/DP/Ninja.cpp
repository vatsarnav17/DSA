//MEMOIZATION

class Solution {
    public:
      int f(int day,int last,vector<vector<int>>& arr,vector<vector<int>> &dp)
      {
          if(day==0)
          {
              int maxi=0;
              for(int i=0;i<=2;i++)
              {
                  if(last!=i)
                  {
                      maxi=max(maxi,arr[0][i]);
                  }
              }
              return maxi;
          }
          
          if(dp[day][last]!=-1)
              return dp[day][last];
          
          int maxi=0;
          for(int i=0;i<=2;i++)
          {
              int points=0;
              if(last!=i)
              {
                  points = arr[day][i] + f(day-1,i,arr,dp);
                  maxi=max(maxi,points);
              }
          }
          return dp[day][last]= maxi;
      }
      int maximumPoints(vector<vector<int>>& arr) 
      {
          int n=arr.size();
          vector<vector<int>> dp(n,vector<int>(4,-1));
          return f(n-1,3,arr,dp);
          
      }
  };

//TABULATION

class Solution {
    public:
      int maximumPoints(vector<vector<int>>& arr) 
      {
          int n = arr.size();
          vector<vector<int>> dp(n, vector<int>(4, -1));
  
          // Correct initialization
          dp[0][0] = max(arr[0][1], arr[0][2]);
          dp[0][1] = max(arr[0][0], arr[0][2]);
          dp[0][2] = max(arr[0][0], arr[0][1]);
          dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});
  
          for (int day = 1; day < n; day++) // Fixed loop variable
          {
              for (int last = 0; last < 4; last++) // Fix: last should go up to 3
              {
                  dp[day][last] = 0; // Corrected syntax
  
                  for (int task = 0; task < 3; task++)
                  {
                      if (task != last)
                      {
                          int point = arr[day][task] + dp[day - 1][task];
                          dp[day][last] = max(dp[day][last], point);
                      }
                  }
              }
          }
          return dp[n - 1][3];
      }
  };

//SPACE OPTIMISED

class Solution {
    public:
      int maximumPoints(vector<vector<int>>& arr) {
          int n = arr.size();
          vector<int> prev(4,0);
          
          prev[0]=max({arr[0][1],arr[0][2]});
          prev[1]=max({arr[0][0],arr[0][2]});
          prev[2]=max({arr[0][0],arr[0][1]});
          prev[3]=max({arr[0][0],arr[0][1],arr[0][2]});
          
          for(int day=1;day<n;day++){
              vector<int> temp(4,0);
              for(int last=0;last<4;last++){
                  temp[last]=0;
                  for(int task=0;task<3;task++){
                      if(task!=last)
                      {
                          temp[last]=max(temp[last],arr[day][task]+prev[task]);
                      }
                  }
              }
              prev=temp;
          }
          return prev[3];
      }
  };