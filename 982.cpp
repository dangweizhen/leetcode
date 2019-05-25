class Solution {
public:
    int countTriplets(vector<int>& A) {
        int res = 0;
        int l = A.size();
        vector<int> bitmap(65537,-1);
        for(int i = 0;i < l;i ++)
            for(int j = 0;j < l;j ++)
            {
                int x = A[i]&A[j];
                if(bitmap[x] < 0)
                {
                    bitmap[x] = 0;
                    for(int k = 0;k < l;k ++)
                    {
                        if((A[k]&x) == 0)
                            bitmap[x] ++;
                    }
                }
                res += bitmap[x];
            }
        return res;
    }
};