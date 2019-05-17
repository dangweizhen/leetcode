class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int tmp;
        int tmp2;
        int tmp_o;
        for(int i = 0;i <= (n-1)/2;i ++)
            for(int j = 0;j < n/2;j ++)
            {
                int x = i, y = j;
                tmp = matrix[i][j];
                for(int k = 0;k < 4;k ++)
                { 
                    tmp2 = matrix[y][n-1-x];
                    matrix[y][n-1-x] = tmp;
                    tmp = tmp2;
                    tmp_o = x;
                    x = y;
                    y = n-1-tmp_o;
                    //cout << x << " " << y << endl;
                }
                
            }
    }
};