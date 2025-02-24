class Solution {
    public:
        int minimizeCost(int k, std::vector<int>& height) {
            int n = height.size();
            std::vector<int> dp(n, INT_MAX); // Initialize dp array with large values
            dp[0] = 0; // Starting position has 0 cost
    
            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= k; j++) {
                    if (i - j >= 0) { // Ensure valid index
                        int jump = dp[i - j] + std::abs(height[i] - height[i - j]);
                        dp[i] = std::min(dp[i], jump);
                    }
                }
            }
            return dp[n - 1]; // Return minimum cost to reach last stone
        }
    };