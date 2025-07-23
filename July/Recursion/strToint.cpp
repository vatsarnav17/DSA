class Solution {
public:
    int MAX = INT_MAX;
    int MIN = INT_MIN;

    int myAtoi(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        return helper(s,0,0,1,false);
    }

    int helper(const string&s,int i, long ans,int sign,bool signSet)
    {
        if(i>=s.length())
        {
            return (int)(ans*sign);
        }

        char c = s[i];

        if(!signSet && c==' ')
        {
            return helper(s,i+1,ans,sign,false);
        }

        if(!signSet && (c=='+'||c=='-')){
            sign = (c=='-')?-1:1;
            return helper(s,i+1,ans,sign,true); 
        }

        if(isdigit(c))
        {
            ans=ans*10 +(c-'0');

            if(sign==1 && ans>=MAX)return MAX;
            if(sign==-1&& -ans <=MIN) return MIN;

            return helper(s,i+1,ans,sign,true);
        }

        return (int)(ans*sign);

    }
};