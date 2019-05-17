class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        if(n == 0) return res;
        int x = 0;
        int y = 0;
        while(m > 0 && n > 0)
        {
            if(m == 1)
            {
                for(int i = 0;i < n;i ++)
                {
                    res.push_back(matrix[x][y]);
                    y++;
                }
                break;
            }
            if(n == 1)
            {
                for(int i = 0;i < m;i ++)
                {
                    res.push_back(matrix[x][y]);
                    x ++;
                }
                break;
            }
            else
            {
                for(int i = 0;i < n-1;i ++)
                {
                    res.push_back(matrix[x][y]);
                    y ++;
                }
                for(int i = 0;i < m-1;i ++)
                {
                    res.push_back(matrix[x][y]);
                    x ++;
                }
                for(int i = 0;i < n-1;i ++)
                {
                    res.push_back(matrix[x][y]);
                    y --;
                }
                for(int i = 0;i < m-1;i ++)
                {
                    res.push_back(matrix[x][y]);
                    x --;
                }
                x ++;
                y ++;
            }
            m -= 2;
            n -= 2;
        }
        return res;
    }
};