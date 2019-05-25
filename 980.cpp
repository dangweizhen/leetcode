class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid, int x, int y, int f_x, int f_y, int remain)
    {
        if(grid[x][y] == 2)
        {
            if(remain == 0) return true;
            else return false;
        }
        int res = 0;
        grid[x][y] = -1;
        if(x + 1 < grid.size() && grid[x+1][y] != -1)
        {
             res += uniquePathsIII(grid, x+1, y, f_x, f_y, remain-1);
        }
        if(x - 1 >= 0 && grid[x-1][y] != -1)
        {
             res += uniquePathsIII(grid, x-1, y, f_x, f_y, remain-1);
        }
        if(y + 1 < grid[0].size() && grid[x][y+1] != -1)
        {
             res += uniquePathsIII(grid, x, y+1, f_x, f_y, remain-1);
        }
        if(y - 1 >= 0 && grid[x][y-1] != -1)
        {
             res += uniquePathsIII(grid, x, y-1, f_x, f_y, remain-1);
        }
        grid[x][y] = 1;
        return res;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int l_x = grid.size();
        if(l_x == 0) return 0;
        int l_y = grid[0].size();
        int x, y;
        int f_x, f_y;
        int remain = 0;
        for(int i = 0;i < l_x;i ++)
            for(int j = 0;j < l_y;j ++)
            {
                if(grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                    remain ++;
                }
                if(grid[i][j] == 2)
                {
                    f_x = i;
                    f_y = j;
                    //remain ++;
                }
                if(grid[i][j] == 0)
                    remain ++;
            }
        return uniquePathsIII(grid, x, y, f_x, f_y, remain);
    }
};