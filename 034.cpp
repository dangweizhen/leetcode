class Solution {
public:
	void find(vector<int>& nums, int target, int st, int ed, vector<int>& res)
	{
		if(st >= ed) return;
		int mid = (st + ed) / 2;
		if(nums[mid] > target) 
		{
			find(nums, target, st, mid, res);
			return;
		}
		if(nums[mid] < target) 
		{
			find(nums, target, mid+1, ed, res);
			return;
		}
		if(res[0] < 0 || res[0] > mid)
		{
			res[0] = mid;
			find(nums, target, st, mid, res);
		}
		if(res[1] < 0 || res[1] < mid)
		{
			res[1] = mid;
			find(nums, target, mid+1, ed, res);
		}
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = nums.size();
        vector<int> res(2,-1);
        if(l == 0) return res;
        find(nums, target, 0, l, res);
        return res;
    }
};