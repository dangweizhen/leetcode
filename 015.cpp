class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        if(nums.size() < 3) return res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size()-2;i ++)
        {
        	int j = i + 1;
        	int k = nums.size()-1;
        	if(nums[i] > 0) break;
        	if(i > 0 && nums[i] == nums[i-1]) continue;
        	while(j < k)
        	{
        		if(nums[i] + nums[j] + nums[k] == 0)
        		{
        			res.push_back({nums[i],nums[j],nums[k]});
        			j ++;
        			k --;
        			while(j < k && nums[j] == nums[j-1])
        				j ++;
        			while(j < k && nums[k] == nums[k+1])
        				k --;
        			continue;
        		}
        		if(nums[i] + nums[j] + nums[k] > 0)
        		{
        			k --;
        		}
        		if(nums[i] + nums[j] + nums[k] < 0)
        		{
        			j ++;
        		}
        	}
        }
        return res;
    }
};