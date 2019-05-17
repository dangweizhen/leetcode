class Solution {
public:
    int totalNQueens(int n, vector<string>& ans, int l)
    {
        if(n == l)
        {
            return 1;
        }
        int res = 0;
        for(int i = 0;i < n;i ++)
        {
            //Q at ans[l][i]
            bool suit = true;
            for(int j = 0;j < l;j ++)
            {
                if(ans[j][i] == 'Q')
                {
                    suit = false;
                    break;
                }
                if(i+j-l >= 0 && ans[j][i+j-l] == 'Q')
                {
                    suit = false;
                    break;
                }
                if(l-j+i < n && ans[j][l-j+i] == 'Q')
                {
                    suit = false;
                    break;
                }
            }
            if(suit)
            {
                ans[l][i] = 'Q';
                res += totalNQueens(n, ans, l+1);
                ans[l][i] = '.';
            }
        }
        return res;
    }
    int totalNQueens(int n) {
        int res = 0;
        if(n <= 1) return n;
        string init(n,'.');
        vector<string> ans(n,init);
        for(int i = 0;i < n/2;i ++)
        {
            ans[0][i] = 'Q';
            res += 2*totalNQueens(n, ans, 1);
            ans[0][i] = '.';
        }
        if(n % 2)
        {
            ans[0][n/2] = 'Q';
            res += totalNQueens(n, ans, 1);
            ans[0][n/2] = '.';
        }
        return res;
    }
};