class Solution {
public:
    bool perfect_square(int& a, int& b)
    {
        int sum = a+b;
        int sq = (int)(sqrt(sum)+0.01);
        //cout << a << " " << b << " " << (sum == sq*sq) << endl;
        return sum == sq*sq;
    }
    int numSquarefulPerms(vector<int>& A, vector<bool>& visited, int last_n, int remain)
    {
    	if(remain == 0) return 1;
    	int k = 0;
    	int res = 0;
    	while(k < A.size())
    	{
    		if(visited[k])
    		{
    			k ++;
    			continue;
    		}
    		if(last_n < 0 || (!visited[k] && perfect_square(last_n, A[k])))
    		{
    			visited[k] = true;
    			res += numSquarefulPerms(A, visited, A[k], remain-1);
    			visited[k] = false;
    		}
    		k++;
			while(k < A.size())
			{
				if(A[k] == A[k-1]) k++;
				else break;
			}
    		
    	}
    	return res;
    }
    int numSquarefulPerms(vector<int>& A) {
        int l = A.size();
        if(l == 0) return 0;
        sort(A.begin(), A.end());
        vector<bool> visited(l, false);
        return numSquarefulPerms(A, visited, -1, l);
    }
};