class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hashmap(256, 0);
        int L=0,R=0, minlen=INT_MAX, start=-1, cnt=0;

        for(int i=0;i<t.size();i++)
        {
            ++hashmap[t[i]];
        }

        while(R<s.size())
        {
            if(hashmap[s[R]]>0)
                cnt=cnt+1;
            --hashmap[s[R]];
            
            while(cnt==t.size())
            {
                if(R-L+1 < minlen)
                    {
                        minlen = R-L+1;
                        start = L;
                    }
                ++hashmap[s[L]];
                
                if(hashmap[s[L]]>0)
                    cnt = cnt - 1;
                ++L;
            }
            R++;
        }
        return start==-1? "":s.substr(start, minlen);

    }
};