class Solution {
public:
    bool isMatch(string s, string p) {
        const int x = s.length()+1;
        const int y = p.length()+1;
        bool res[x][y];
        for(int i = 0;i < x;i ++)
            for(int j = 0;j < y;j ++)
                res[i][j] = false;
        res[0][0] = true;
        for(int i = 0;i < p.length();i ++)
        {
            if(p[i] == '*') res[0][i+1] = res[0][i-1];
        }
        for(int i = 0;i < s.length();i ++)
            for(int j = 0;j < p.length();j ++)
            {
                if(p[j] == '.' || p[j] == s[i])
                    res[i+1][j+1] = res[i][j];
                if(p[j] == '*')
                {
                    if(p[j-1] != '.' && p[j-1] != s[i]) res[i+1][j+1] = res[i+1][j-1];
                    else
                        res[i+1][j+1] = res[i+1][j-1] || res[i][j-1] || res[i][j+1];
                }
            }
        return res[x-1][y-1];
    }
};