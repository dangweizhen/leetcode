class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = nums.size();
        if(l == 0) return 0;
        int res = nums[0];
        int max_sum = nums[0];
        for(int i = 1;i < l;i ++)
        {
            max_sum = max(nums[i],max_sum+nums[i]);
            if(max_sum > res) res = max_sum;
        }
        return res;
    }
};