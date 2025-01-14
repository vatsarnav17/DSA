class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
    const int MOD = 1e9 + 7;
    
    // Stacks to store indices of the elements
    stack<int> prevSmaller, nextSmaller;
    
    // Arrays to store PSE and NSE values
    vector<int> pse(n, -1), nse(n, n);
    
    // Find Previous Smaller Element (PSE) for each element
    for (int i = 0; i < n; ++i) {
        while (!prevSmaller.empty() && arr[prevSmaller.top()] >= arr[i]) {
            prevSmaller.pop();
        }
        if (!prevSmaller.empty()) {
            pse[i] = prevSmaller.top();
        }
        prevSmaller.push(i);
    }
    
    // Find Next Smaller Element (NSE) for each element
    for (int i = n - 1; i >= 0; --i) {
        while (!nextSmaller.empty() && arr[nextSmaller.top()] > arr[i]) {
            nextSmaller.pop();
        }
        if (!nextSmaller.empty()) {
            nse[i] = nextSmaller.top();
        }
        nextSmaller.push(i);
    }
    
    // Calculate the result using the formula for sum of subarray minimums
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        result += arr[i] * left * right;
        result %= MOD;
    }
    
    return result;
    }
};