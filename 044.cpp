class Solution {
public:
    bool isMatch(string s, string p) {
        const int ls = s.length();
        const int lp = p.length();
        bool res[ls+1][lp+1]={{0}};
        res[0][0] = true;
        for(int i = 1;i <= ls;i ++)
            res[i][0] = false;
        for(int i = 1;i <= lp;i ++)
            res[0][i] = (p[i-1] == '*' && res[0][i-1]);
        for(int i = 1;i <= ls;i ++)
            for(int j = 1;j <= lp;j ++)
            {
                //res[i][j]
                if(p[j-1] == '?' || p[j-1] == s[i-1]) res[i][j] = res[i-1][j-1];
                if(p[j-1] == '*') res[i][j] = res[i-1][j-1] || res[i][j-1] || res[i-1][j];
            }
        return res[ls][lp];
    }
};