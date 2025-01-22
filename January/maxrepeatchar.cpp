class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0,right=0,maxfreq=0,maxlen=0;
        int hash[26]={0};
        while(right<n)
        {
            hash[s[right]-'A']++;
            if(hash[s[right]-'A'] > maxfreq){
                maxfreq=hash[s[right]-'A'];
            }
            if((right-left+1)-maxfreq > k)
            {
                hash[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};