class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l = A.size();
        vector<int> res;
        int pos = 0;
        for(;pos < l;pos ++)
            if(A[pos] > 0) break;
        int neg = pos-1;
        while(neg >= 0 && pos < l)
        {
            if(A[neg]*A[neg] < A[pos]*A[pos])
            {
                res.push_back(A[neg]*A[neg]);
                neg --;
            }
            else
            {
                res.push_back(A[pos]*A[pos]);
                pos ++;
            }
        }
        if(neg < 0)
        {
            for(;pos < l;pos ++)
            {
                res.push_back(A[pos]*A[pos]);
            }
        }
        else
        {
            for(;neg >= 0;neg --)
            {
                res.push_back(A[neg]*A[neg]);
            }
        }
        return res;
    }
};