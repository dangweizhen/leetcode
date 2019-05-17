class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        const int l = s.length();
        if(l == 0) return 0;
        int right[l];
        int max_len = 0;
        for(int i = 0;i < l;i ++)
        {
            if(s[i] == '(')
            {
                right[i] = -1;
                st.push(i);
            }
            else
            {
                if(st.empty())
                {
                    right[i] = -1;
                }
                else
                {
                    right[i] = st.top();
                    st.pop();
                }
            }
        }
        int p = l-1;
        int tmp_len = 0;
        while(p >= 0)
        {
            if(s[p] == ')' && right[p] >= 0)
            {
                tmp_len += (p-right[p]+1);
                if(tmp_len > max_len) max_len = tmp_len;
                p = right[p]-1;
            }
            else
            {
                tmp_len = 0;
                p--;
            }
        }
        return max_len;
    }
};