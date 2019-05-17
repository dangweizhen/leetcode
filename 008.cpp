class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int sgn = 1;
        int res = 0;
        while(i < str.length())
        {
            if(str[i] != ' ') break;
            i ++;
        }
        if(str[i] == '+' || str[i] == '-')
        {
            sgn = str[i]=='+' ? 1:-1;
            i ++;
        }
        while(i < str.length())
        {
            if(str[i] < '0' || str[i] > '9') break;
            if(res > 214748364 || (res == 214748364 && str[i]-'0' > 7))
                return 2147483647;
            if(res < -214748364 || (res == -214748364 && str[i]-'0' > 8))
                return -2147483648;
            res *= 10;
            res += sgn*(str[i]-'0');
            i ++;
        }
        return res;
    }
};