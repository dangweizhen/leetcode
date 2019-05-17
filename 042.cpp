class Solution {
public:
    int trap(vector<int>& height) {
        const int l = height.size();
        if(l <= 2) return 0;
        int water[l] = {0};
        int cur = 0;
        for(int i = 0;i < l;i ++)
        {
            if(cur >= height[i])
                water[i] = cur;
            else
                cur = height[i];
        }
        cur = 0;
        for(int i = l-1;i >= 0;i --)
        {
            water[i] = min(water[i],cur);
            if(cur < height[i])
                cur = height[i];
        }
        int res = 0;
        for(int i = 0;i < l;i ++)
        {
            //cout << water[i] << " ";
            if(water[i] > height[i])
            {
                res += (water[i] - height[i]);
            }
        }
        return res;
    }
};