class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string res(s);
        int cur_len = 0;
        //first row
        int n = 0;
        while(n < s.length())
        {
            res[cur_len]=s[n];
            cur_len++;
            n = n+2*numRows-2;
        }
        //row between first and last
        for(int i = 1;i < numRows-1;i ++)
        {
            n = i;
            while(n < s.length())
            {
                int next_n = n+2*numRows-2;
                res[cur_len]=s[n];
                cur_len++;
                n += (2*numRows-2-2*i);
                if(n < s.length())
                {
                    res[cur_len]=s[n];
                    cur_len++;
                    n = next_n;
                }
            }
        }
        //last row 
        n = numRows-1;
        while(n < s.length())
        {
            res[cur_len]=s[n];
            cur_len++;
            n = n+2*numRows-2;
        }
        return res;
    }
};