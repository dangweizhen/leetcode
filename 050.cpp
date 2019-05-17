class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) return 1.0/x*myPow(1.0/x, -(n+1));
        double res = x;
        double half = myPow(x, n/2);
        return half*half*(n%2?x:1);
    }
};