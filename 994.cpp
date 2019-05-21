class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int l_x = grid.size();
        if(l_x == 0) return 0;
        int l_y = grid[0].size();
        if(l_y == 0) return 0;
        queue<vector<int>> rotten;
        for(int i = 0;i < l_x;i ++)
            for(int j = 0;j < l_y;j ++)
            {
                if(grid[i][j] == 2)
                    rotten.push(vector({i,j,0}));
            }
        int res = 0;
        while(!rotten.empty())
        {
            vector<int> rotten_info(rotten.front());
            rotten.pop();
            int x = rotten_info[0];
            int y = rotten_info[1];
            int t = rotten_info[2];
            res = t;
            if(x-1>=0 && grid[x-1][y] == 1) 
            {
                grid[x-1][y] = 2;
                rotten.push(vector({x-1,y,t+1}));
            }
            if(x+1<l_x && grid[x+1][y] == 1) 
            {
                grid[x+1][y] = 2;
                rotten.push(vector({x+1,y,t+1}));
            }
            if(y-1>=0 && grid[x][y-1] == 1) 
            {
                grid[x][y-1] = 2;
                rotten.push(vector({x,y-1,t+1}));
            }
            if(y+1<l_y && grid[x][y+1] == 1) 
            {
                grid[x][y+1] = 2;
                rotten.push(vector({x,y+1,t+1}));
            }
        }
        for(int i = 0;i < l_x;i ++)
            for(int j = 0;j < l_y;j ++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        return res;
    }
};