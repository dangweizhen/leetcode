class Solution {
public:
    void solveNQueens(int n, vector<string>& ans, int l, vector<vector<string>>& res)
    {
        if(n == l)
        {
            res.push_back(ans);
            return;
        }
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
                solveNQueens(n, ans, l+1, res);
                ans[l][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n == 0) return res;
        string init(n,'.');
        vector<string> ans(n,init);
        solveNQueens(n, ans, 0, res);
        return res;
    }
};