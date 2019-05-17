class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_len = 0;
        for(int i = 0;i < nums.size();i ++)
        {
            if(max_len < i) return false;
            max_len = max(max_len, i+nums[i]);
        }
        return true;
    }
};