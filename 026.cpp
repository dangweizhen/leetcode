class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) nums.size();
        int index = 0;
        int n = -1;
        int i = 0;
        while(i < nums.size())
        {
            n = nums[i];
            nums[index++]=n;
            for(;i < nums.size();i ++)
                if(nums[i] != n)
                    break;
        }
        return index;
    }
};