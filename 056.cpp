class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l = intervals.size();
        if(l <= 1) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(), [](vector<int>a, vector<int> b){return a[0] < b[0];});
        int cur_st = intervals[0][0];
        int cur_ed = intervals[0][1];
        vector<int> tmp(2);
        for(int i = 0;i < l;i ++)
        {
            if(intervals[i][0] > cur_ed)
            {
                tmp[0] = cur_st;
                tmp[1] = cur_ed;
                res.push_back(tmp);
                cur_st = intervals[i][0];
                cur_ed = intervals[i][1];
            }
            else
            {
                //overlap
                cur_ed = max(intervals[i][1],cur_ed);
            }
        }
        tmp[0] = cur_st;
        tmp[1] = cur_ed;
        res.push_back(tmp);
        return res;
    }
};