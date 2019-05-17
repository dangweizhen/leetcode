class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = size(height)-1;
        int max_a = -1;
        while(left < right)
        {
            int area = min(height[left], height[right])*(right-left);
            if(max_a < area)
                max_a = area;
            if(height[left] <= height[right]) left ++;
            else right --;
        }
        return max_a;
    }
};