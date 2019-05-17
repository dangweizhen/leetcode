class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int rev = 0;
        int ori = x;
        while(ori != 0)
        {
            if(rev > 214748364 || (rev == 214748364 && ori %10 > 7)) return false;
            rev *= 10;
            rev += ori%10;
            ori /= 10;
        }
        return x == rev;
    }
};