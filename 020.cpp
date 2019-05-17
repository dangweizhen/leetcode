class Solution {
public:
    bool isValid(string s) {
        stack<char> s_p;
        for(int i = 0;i < s.length();i ++)
        {
            switch(s[i])
            {
                case '(':
                case '{':
                case '[':
                    s_p.push(s[i]);
                    break;
                case ')':
                    if(s_p.empty()) return false;
                    if(s_p.top()!='(')
                        return false;
                    s_p.pop();
                    break;
                case '}':
                    if(s_p.empty()) return false;
                    if(s_p.top()!='{')
                        return false;
                    s_p.pop();
                    break;
                case ']':
                    if(s_p.empty()) return false;
                    if(s_p.top()!='[')
                        return false;
                    s_p.pop();
                    break;
                    break;
                default:
                    break;
            }
        }
        return s_p.empty();
    }
};