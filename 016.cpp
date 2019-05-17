class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res;
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size()-2;i ++)
        {
        	int j = i + 1;
        	int k = nums.size()-1;
        	//if(nums[i] > target) break;
        	if(i > 0 && nums[i] == nums[i-1]) continue;
        	while(j < k)
        	{
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target) < abs(res-target))
                    res = sum;
        		if(sum == target)
        			return target;
        		if(sum > target)
        		{
        			k --;
        		}
        		if(sum < target)
        		{
        			j ++;
        		}
        	}
        }
        return res;
    }
};