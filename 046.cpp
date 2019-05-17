class Solution {
public:
    bool next(vector<int>& a, int l)
    {
        for(int i = l-1;i >= 1;i --)
        {
            if(a[i] > a[i-1])
            {
                //next permutation
                for(int j = l-1; j >= i;j --)
                {
                    if(a[j] > a[i-1])
                    {
                        int tmp = a[j];
                        a[j] = a[i-1];
                        a[i-1] = tmp;
                        break;
                    }    
                }
                sort(a.begin()+i,a.end());
                return true;
            }
        }
        return false;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n == 0) return res;
        vector<int> auxi(n);
        vector<int> tmp(nums);
        for(int i = 0;i < n;i ++)
            auxi[i] = i;
        res.push_back(tmp);
        while(next(auxi, n))
        {
            for(int i = 0;i < n;i ++)
                tmp[i] = nums[auxi[i]];
            res.push_back(tmp);
        }
        return res;
    }
};