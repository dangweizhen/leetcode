class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int i = 0;
        while(i < s.length())
        {
            switch(s[i])
            {
                case 'M':
                    res += 1000;
                    break;
                case 'D':
                    res += 500;
                    break;
                case 'C':
                    if(i+1 < s.length() && s[i+1] == 'M')
                    {
                        res += 900;
                        i ++;
                        break;
                    }
                    if(i+1 < s.length() && s[i+1] == 'D')
                    {
                        res += 400;
                        i ++;
                        break;
                    }
                    res += 100;
                    break;
                case 'L':
                    res += 50;
                    break;
                case 'X':
                    if(i+1 < s.length() && s[i+1] == 'C')
                    {
                        res += 90;
                        i ++;
                        break;
                    }
                    if(i+1 < s.length() && s[i+1] == 'L')
                    {
                        res += 40;
                        i ++;
                        break;
                    }
                    res += 10;
                    break;
                case 'V':
                    res += 5;
                    break;
                case 'I':
                    if(i+1 < s.length() && s[i+1] == 'X')
                    {
                        res += 9;
                        i ++;
                        break;
                    }
                    if(i+1 < s.length() && s[i+1] == 'V')
                    {
                        res += 4;
                        i ++;
                        break;
                    }
                    res += 1;
                    break;
                default:
                    break;
            }
            i ++;
        }
        return res;
    }
};