class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_map;
        vector<int> ans(2);
        for(int i = 0;i < nums.size(); ++i)
        {
            unordered_map<int, int>::iterator res = index_map.find(target-nums[i]);
            if(res != index_map.end())
            {
                ans[0] = res->second;
                ans[1] = i;
                return ans;
            }
            else
                index_map[nums[i]] = i;
        }
        return ans;
    }
};