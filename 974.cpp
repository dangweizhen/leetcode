class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int l = A.size();
        if(l == 0) return 0;
        vector<int> remain(K,0);
        int sum = 0;
        remain[0] = 1;
        for(int i = 0;i < l;i ++)
        {
            sum += A[i];
            sum %= K;
            if(sum < 0) sum += K;
            remain[sum] ++;
        }
        int res = 0;
        for(int i = 0;i < K;i ++)
        {
            res += (remain[i]*(remain[i]-1)/2);
        }
        return res;
    }
};