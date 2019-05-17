class Solution {
public:
    int bi_search(vector<int>& nums, int target, int st, int s, int e)
    {
        int l = nums.size();
        if(s == e) return -1;
        int mid = (s+e)/2;
        if(nums[(mid+st)%l] == target) 
        {
            //cout << mid;
            return (mid+st)%l;
        }
        if(nums[(mid+st)%l] > target) return bi_search(nums, target, st, s, mid);
        if(nums[(mid+st)%l] < target) return bi_search(nums, target, st, mid+1, e);
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = nums.size();
        if(l == 0) return -1;
        int st = 0;
        for(int i = 1;i < l;i ++)
        {
            if(nums[i] < nums[0])
            {
                st = i;
                break;
            }
        }
        return bi_search(nums, target, st, 0, l);
    }
};