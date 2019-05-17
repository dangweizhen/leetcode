class Solution {
public:

    int strStr(string haystack, string needle) {
        const int k = needle.length();
        if(needle == "") return 0;
        if(haystack == "")return -1;
        int next[k];
        //build next
        next[0] = -1;
        int last_next = -1;
        int next_c = 1;
        while(next_c < k)
        {
        	if(last_next < 0 || needle[next_c-1] == needle[last_next])
        	{
        		next[next_c] = last_next + 1;
        		next_c ++;
        		last_next ++;
        	}
        	else
        		last_next = next[last_next];

        }
        //check
        int h_c = 0, n_c = 0;
        while(h_c < haystack.length() && n_c < (int)needle.length())
        {
        	if(n_c == -1 || haystack[h_c] == needle[n_c])
        	{
        		h_c ++;
        		n_c ++;
        	}
        	else
        	{
        		n_c = next[n_c];
        	}
        }
        if(n_c == needle.length())
        	return h_c-n_c;
        return -1;
    }
};