class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_position[128];
        int max_len = 0;
        for(int i = 0;i < 128; ++i)
            last_position[i] = -1;
        int st = 0, ed = 0;
        while(ed < s.length())
        {
        	int new_char = (int)s[ed];
        	if(last_position[new_char] < 0)
        	{
        		last_position[new_char] = ed;
        		++ ed;
        	}
        	else
        	{
        		max_len = max(max_len, ed-st);
        		for(;st < last_position[new_char];++st)
        			last_position[(int)s[st]] = -1;
        		last_position[new_char] = ed;
        		++st;
                ++ed;
        	}
        }
        return max(ed-st,max_len);
    }
};