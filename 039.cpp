class Solution {
public:
    void combinationSum(vector<int>& candidates, int target, int st, vector<int>& ans, vector<vector<int>>& res)
    {
        for(int i = st;i < candidates.size();i ++)
        {
            if(candidates[i] > target) return;
            
            if(candidates[i] == target)
            {
                ans.push_back(candidates[i]);
                res.push_back(ans);
                return;
            }
            vector<int> tmp(ans);
            tmp.push_back(candidates[i]);
            combinationSum(candidates, target-candidates[i],i,tmp, res);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        if(target <= 0) return res;
        vector<int> ans;
        combinationSum(candidates, target, 0, ans, res);
        return res;
    }
};