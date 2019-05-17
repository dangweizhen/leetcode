class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row
        for(int i = 0;i < 9;i ++)
        {
            bool res[9] = {0};
            for(int j = 0;j < 9;j ++)
            {
                if(board[i][j] == '.') continue;
                if(res[board[i][j]-'1']) return false;
                else res[board[i][j]-'1'] = true;
            }
        }
        //column
        for(int i = 0;i < 9;i ++)
        {
            bool res[9] = {0};
            for(int j = 0;j < 9;j ++)
            {
                if(board[j][i] == '.') continue;
                if(res[board[j][i]-'1']) return false;
                else res[board[j][i]-'1'] = true;
            }
        }
        //square
        for(int i = 0;i < 3;i ++)
            for(int j = 0;j < 3;j ++)
            {
                bool res[9] = {0};
                for(int m = 0;m < 3;m ++)
                    for(int n = 0;n < 3;n ++)
                    {
                        //if(i == 0 && j == 2) cout << board[i*3+m][j*3+n] << " ";
                        if(board[i*3+m][j*3+n] == '.') continue;
                        if(res[board[i*3+m][j*3+n]-'1']) return false;
                        else res[board[i*3+m][j*3+n]-'1'] = true;
                    }
            }
        return true;
    }
};