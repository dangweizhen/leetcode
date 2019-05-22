class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int l = A.size();
        if(l <= 1) return (int)(l==K);
        /*
        given that [ed1, st] [ed2, st] are max and min substr ends at st with K distinct
        counter record number of letter in [ed2, st]
        */
        int ed1 = 0;
        int ed2 = 0;
        int st = 0;
        int res = 0;
        int i_count = 0;
        vector<int> counter(l, 0);
        for(int i = 0;i < l;i ++)
        {
            if(counter[A[i]-1] == 0)
                i_count ++;
            counter[A[i]-1] ++;
            if(i_count == K)
            {
                st = i;
                break;
            }
        }
        if(i_count < K) return 0;
        while(ed2 <= st)
        {
            if(counter[A[ed2]-1] == 1)
                break;
            else
            {
                counter[A[ed2]-1] --;
                ed2 ++;
            }
        }
        res += (ed2-ed1+1);
        st ++;
        while(st < l)
        {
            if(counter[A[st]-1] == 0)
            {
                counter[A[st]-1] = 1;
                while(ed2 <= st)
                {
                    counter[A[ed2]-1] --;
                    if(counter[A[ed2]-1] == 0)
                    {
                        ed2 ++;
                        ed1 = ed2;
                        break;
                    }
                    ed2 ++;
                }
                while(ed2 <= st)
                {
                    if(counter[A[ed2]-1] == 1)
                        break;
                    else
                    {
                        counter[A[ed2]-1] --;
                        ed2 ++;
                    }
                    
                }
            }
            else
            {
                counter[A[st]-1] ++;
                while(ed2 <= st)
                {
                    if(counter[A[ed2]-1] == 1)
                        break;
                    else
                    {
                        counter[A[ed2]-1] --;
                        ed2 ++;
                    }
                }
            }
            res += (ed2-ed1+1);
            st ++;
        }
        return res;
    }
};