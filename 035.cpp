class Solution {
public:
	int find(vector<int>& nums, int target, int st, int ed)
	{
        //cout << st << " " << ed << " ";
        if(st == nums.size()) return st;
		if(st >= ed) return (nums[st] > target ? st:st+1);
		int mid = (st+ed)/2;
		if(nums[mid] == target) return mid;
		if(nums[mid] > target) return find(nums, target, st, mid);
		return find(nums, target, mid+1, ed);
	}
    int searchInsert(vector<int>& nums, int target) {
        int l = nums.size();
        if(l == 0) return 0;
        return find(nums, target, 0 ,l);
    }
};