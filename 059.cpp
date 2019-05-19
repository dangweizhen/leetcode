class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n == 0) return res;
        for(int i = 0;i < n;i ++)
            res.push_back(vector(n,1));
        int counter = 1;
        int x = 0;
        int y = 0;
        while(n > 0)
        {
            if(n == 1)
            {
                res[x][y] = counter;
                break;
            }
            for(int i = 0; i < n-1;i ++)
            {
                res[x][y] = counter++;
                y ++;
            }
            for(int i = 0;i < n-1;i ++)
            {
                res[x][y] = counter++;
                x ++;
            }
            for(int i = 0;i < n-1;i ++)
            {
                res[x][y] = counter++;
                y --;
            }
            for(int i = 0;i < n-1;i ++)
            {
                res[x][y] = counter++;
                x --;
            }
            x ++;
            y ++;
            n-=2;
        }
        return res;
    }
};