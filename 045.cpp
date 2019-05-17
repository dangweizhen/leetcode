class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int last = 0;
        int res = 0;
        for(int i = 0;i < nums.size();i ++)
        {
            if(i > last)
            {
                last = cur;
                res ++;
            }
            cur = max(cur, i + nums[i]);
        }
        return res;
    }
};