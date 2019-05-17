class Solution {
public:
	char get_d(int n)
	{
		switch(n)
		{
			case 2:
				return 'a';
			case 3:
				return 'd';
			case 4:
				return 'g';
			case 5:
				return 'j';
			case 6:
				return 'm';
			case 7:
				return 'p';
			case 8:
				return 't';
			case 9:
				return 'w';
			default:
				return '0';
		}
		return 0;
	}
	bool last(char c)
	{
		char a[8] = {'c','f','i','l','o','s','v','z'};
		for(int i = 0;i < 8;i ++)
		{
			if(a[i] == c) return true;
		}
		return false;

	}
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int l = digits.length();
        if(l == 0) return res;
        string s(l,'a');
        for(int i = 0;i < l;i ++)
        	s[i] = get_d(digits[i]-'0');
        res.push_back(s);
        while(true)
        {
	       	for(int i = l-1;i >= 0;i --)
	       	{
	       		if(!last(s[i]))
	       		{
	       			s[i] += 1;
	       			res.push_back(s);
	       			break;
	       		}
	       		else
	       		{
	       			s[i] = get_d(digits[i]-'0');
	       			if(i == 0) return res;
	       		}
	       	}
	    }
        return res;
    }
};