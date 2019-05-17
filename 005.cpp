#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
	int get(string s, int i)
	{
		if(i < 0 || i > 2*s.length()+1)
			return -1;
		if(i % 2)
			return s[i/2];
		return -2;

	}

    string longestPalindrome(string s) {
    	if(s == "") return "";
        int l = s.length();
        int max_len = -1;
        int max_c = -1;
        int len[3000];
        int p_r = -1;
        int c_r = -1;
        for(int i = 0;i < 2*l+1;++i)
        {
        	//cout << c_r << " ";
        	if(i > p_r)
        	{
        		//j: first unmatch
        		int j = 1;
        		for(;i+j < 2*l+1 && i-j >= 0; ++j)
        		{
        			if(get(s,i+j) != get(s,i-j))
	        			break;
        		}
        		len[i] = j;
        		p_r = i+j-1;
        		c_r = i;
        		if(j > max_len)
        		{
        			max_c = i;
        			max_len = j;
        		}
        	}
        	else
        	{
        		int sym_p = 2*c_r-i;
        		if(sym_p-len[sym_p]+1 > 2*c_r-p_r)
        			len[i] = len[sym_p];
        		else
        		{
        			int j = p_r-i+1;
        			for(;i+j < 2*l+1 && i-j >= 0; ++j)
	        		{
	        			if(get(s,i+j) != get(s,i-j))
	        				break;
	        		}
	        		len[i] = j;
	        		p_r = i+j-1;
	        		c_r = i;
	        		if(j > max_len)
	        		{
        				max_c = i;
        				max_len = j;
        			}
        		}

        	}
        	//cout << len[i] << " ";
        }
        //cout << endl;
        //cout << max_c << endl;
        return s.substr((max_c-len[max_c]+2)/2,len[max_c]-1);
    }
};

int main()
{
	Solution s;
	cout << s.longestPalindrome("aaaaaaaaaaa") << endl;
	return 0;
}
