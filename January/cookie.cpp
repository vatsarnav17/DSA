class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookieSize) {
    int n = greed.size();
    int m = cookieSize.size();
    sort(greed.begin(), greed.end());
    sort(cookieSize.begin(), cookieSize.end());
    int l = 0;
    int r = 0;
    while (l < m && r < n) {
        if (greed[r] <= cookieSize[l]) {
            r++;
        }
        l++;
    }
    return r;
}
    
};