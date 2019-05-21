class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0;
        int cur_flip = 0;
        vector<bool> A_range(A.size(), false);
        for(int i = 0;i < A.size();i ++)
        {
            int cur_num = (A[i] + cur_flip)%2;
            if(cur_num == 0) 
            {
                res ++;
                if(i+K-1 >= A.size()) return -1;
                A_range[i+K-1] = true;
                cur_flip++;
            }
            if(A_range[i]) cur_flip--;
        }
        return res;
    }
};