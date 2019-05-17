class Solution {
public:
    void generateParenthesis(int n, int l,int r, string s, int remain, vector<string>& res)
    {
        if(r == 0) 
        {
            res.push_back(s);
            return;
        }
        if(remain == 0)
        {
            generateParenthesis(n,l+1,r,s+"(",remain+1,res);
            return;
        }
        if(l == n)
        {
            generateParenthesis(n,l,r-1,s+")",remain-1,res);
            return;
        }
        generateParenthesis(n,l+1,r,s+"(",remain+1,res);
        generateParenthesis(n,l,r-1,s+")",remain-1,res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(n,0,n,"",0,res);
        return res;
    }
};