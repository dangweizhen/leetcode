class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int l = 0;
        bool flag = true;
        while(flag)
        {
            char c;
            for(int i = 0;i < strs.size();i ++)
            {
                if(l == strs[i].length())
                {
                    flag = false;
                    break;
                }
                if(i == 0)
                {
                    c = strs[i][l];
                }
                else
                {
                    if(c != strs[i][l])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            l ++;
        }
        return strs[0].substr(0,l-1);
    }
};