class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = nums.size();
        for(int i = 0;i < l;i ++)
        {
            int k = i;
            while(nums[k] != k+1 && nums[k] <= l && nums[k] >= 1)
            {
                if(nums[nums[k]-1] == nums[k]) break;
                int tmp = nums[nums[k]-1];
                nums[nums[k]-1] = nums[k];
                nums[k] = tmp;
            }
        }
        for(int i = 0;i < l;i ++)
        {
            //cout << nums[i] << " ";
            if(nums[i] != i+1)
                return i+1;
        }
        return l+1;
    }
};