class Solution {
public:
    int reverse(int x) {
        if(x == -2147483648) return 0;
        int n = x > 0 ? x:-x;
        int res = 0;
        while(n)
        {
            if(res > 214748364) return 0;
            if(res == 214748364 && n%10 >= 8) return 0;
            res *= 10;
            res+=n%10;
            n/=10;
        }
        return x > 0 ? res : -res;
    }
};