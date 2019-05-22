class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if(A > 2*B+2 || B > 2*A+2)
            return "";
        if(A == 0)
            return string(B,'b');
        if(B == 0)
            return string(A,'a');
        if(A == 1 && B == 1) return "ab";
        int cur = 0;
        char less_c = A > B ? 'b':'a';
        char more_c = (int)('a'+'b'-less_c);
        int less_n = A > B ? B : A;
        string res(A+B, more_c);
        for(int i = 2;i < A+B; i += 3)
        {
            if(less_n == 0) break;
            res[i] = less_c;
            less_n --;
        }
        for(int i = 1;i < A+B; i += 3)
        {
            if(less_n == 0) break;
            res[i] = less_c;
            less_n --;
        }
        return res;
    }
};