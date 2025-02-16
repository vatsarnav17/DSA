class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size(); // Correct size calculation

        // Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms = 1, maxPlatforms = 1;
        int i = 1, j = 0; // Pointers for arrival and departure

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) { // New train arrives before previous departs
                platforms++;
                i++;
            } else { // Train departs, free up a platform
                platforms--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
};