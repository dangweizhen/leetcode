class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int st = 1;
        int ed = 0;
        int l = A.size();
        if(l <= 1) return l;
        int res = 0;
        //0 == , 1 <, -1 >
        int prev = 0;
        if(A[1] > A[0]) prev = 1;
        else if(A[1] == A[0]) prev = 0;
        else prev = -1;
        while(st < l)
        {
            if(A[st] > A[st-1] && prev == 1)
            {
                st ++;
                prev = -1;
                continue;
            }
            if(A[st] < A[st-1] && prev == -1)
            {
                st ++;
                prev = 1;
                continue;
            }
            //cout << st << " " << ed << endl;
            res = max(res,st-ed);
            ed = st-1;
            while(st < l)
            {
                if(A[st] == A[ed])
                {
                    ed ++;
                    st ++;
                }
                else
                {
                    if(A[st] > A[ed]) prev = 1;
                    else prev = -1;
                    break;
                }
            }
        }
        return max(res,st-ed);
    }
};