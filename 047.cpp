class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> res;
        if(l == 0) return res;
        sort(nums.begin(),nums.end());
        res.push_back(nums);
        bool flag = true;
        while(flag)
        {
            int i = l-1;
            for(;i >= 1;i --)
            {
                if(nums[i] > nums[i-1])
                {
                    for(int j = l-1;j >= i;j--)
                    {
                        if(nums[i-1] < nums[j])
                        {
                            int tmp = nums[i-1];
                            nums[i-1] = nums[j];
                            nums[j] = tmp;
                            sort(nums.begin()+i,nums.end());
                            break;
                        }
                    }
                    res.push_back(nums);
                    break;
                }
            }
            if(i == 0) flag = false;
        }
        
        return res;
    }
};