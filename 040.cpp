class Solution {
public:
    void combinationSum2(vector<int>& candidates, int target, int st, vector<int>& ans, vector<vector<int>>& res)
    {
        int i = st;
        if(0 == target)
        {
            res.push_back(ans);
            return;
        }
        while(i<candidates.size())
        {
            if(candidates[i] > target) return;
            vector<int> tmp(ans);
            int j = 1;
            for(;i + j < candidates.size();j ++)
            {
                if(candidates[i]!=candidates[i+j]) break;
            }
            for(int k = 0;k < j;k ++)
            {
                tmp.push_back(candidates[i]);
                vector<int> tmp2(tmp);
                combinationSum2(candidates, target-(k+1)*candidates[i],i+j,tmp2, res);
            }
            i=i+j;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        if(target <= 0) return res;
        vector<int> ans;
        combinationSum2(candidates, target, 0, ans, res);
        return res;
    }
};