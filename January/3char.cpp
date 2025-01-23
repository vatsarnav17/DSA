class Solution {
public:
    int numberOfSubstrings(string s) {
        int hash[3]={0};
        int l=0,r=0,count=0;
        while(r<=s.length())
        {
            switch(s[r]){
                case 'a':
                    hash[0]++;
                    break;
                
                case 'b':
                    hash[1]++;
                    break;
                
                case 'c':
                    hash[2]++;
                    break;
            }
            while(hash[0]>0 && hash[1]>0 && hash[2]>0)
            {
                count = count + s.length() - r;

                switch (s[l]) {
                    case 'a':
                        hash[0]--;
                        break;
                    case 'b':
                        hash[1]--;
                        break;
                    case 'c':
                        hash[2]--;
                        break;
                }
                l++;
            }
            r++;
        }
        return count;
    }
};