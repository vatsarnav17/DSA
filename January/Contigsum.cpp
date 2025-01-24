class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int s=0,e=0,maxsum=0;
        int n=cardPoints.size();
        int r=n-1;
        for(int i=0;i<k;i++){
            s+=cardPoints[i];
            maxsum=s;
        }
        for(int i=k-1;i>=0;i--){
            s=s-cardPoints[i];
            e=e+cardPoints[r];
            r--;
            maxsum = max(maxsum,e+s);
        }
        return maxsum;
    }
};