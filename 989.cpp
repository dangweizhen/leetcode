class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int l = A.size();
        for(int i = l - 1;i >= 0;i --)
        {
            A[i] += K%10;
            K /= 10;
            K += A[i]/10;
            A[i] %= 10;
            if(K == 0) break;
        }
        while(K != 0)
        {
            A.emplace(A.begin(), K%10);
            K/=10;
        }
        return A;
    }
};