class Solution {
public:
	bool solve(vector<vector<char>>& board)
	{
		for(int i = 0;i < 9;i ++)
		{
			for(int j = 0;j < 9;j ++)
			{
				if(board[i][j] == '.')
				{
					bool res[9] = {0};
					for(int k = 0;k < 9;k ++)
					{
						if(board[i][k] != '.') res[board[i][k]-'1'] = true;
						if(board[k][j] != '.') res[board[k][j]-'1'] = true;
						if(board[(i/3)*3+k/3][(j/3)*3+k%3] != '.') res[board[(i/3)*3+k/3][(j/3)*3+k%3]-'1'] = true;
					}
					for(int k = 0;k < 9;k ++)
					{
						if(!res[k])
						{
							board[i][j] = k+'1';
							if(solve(board)) return true;
						}
					}
					board[i][j] = '.';
					return false;
				}
			}
		}
		return true;
	}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};