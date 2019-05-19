class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        for(;i >= 0;i--)
        {
            if(s[i] != ' ') break;
        }
        int j = i;
        for(;j >= 0;j --)
        {
            if(s[j] == ' ')break;
        }
        return i-j;
    }
};