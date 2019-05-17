class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> m;
        vector<int> res(0);
        if(s == "" || words.size() == 0) return res;
        for(vector<string>::iterator it = words.begin();it != words.end(); it ++)
        {
        	if(m.find(*it) != m.end())
        		m[*it] = m[*it]+1;
        	else
        		m[*it] = 1;
        }
        int l = words[0].length();
        for(int i = 0;i < l;i ++)
        {
        	int st = i;
        	int tot = 0;
        	int ind = i;
        	unordered_map<string, int> w_map;
        	while(ind < s.length())
        	{
        		string w = s.substr(ind, l);
        		if(m.find(w) != m.end())
        		{
        			if(w_map.find(w) != w_map.end())
        				w_map[w] = w_map[w]+1;
        			else
        				w_map[w] = 1;
        			if(w_map[w] > m[w])
        			{
        				int remove_ind = st;
        				while(remove_ind < ind)
        				{
        					string remove_word = s.substr(remove_ind, l);
        					st += l;
        					tot--;
        					w_map[remove_word] = w_map[remove_word]-1;
        					if(remove_word == w)
	        					break;
	        				remove_ind += l;
        				}
        			}
        			tot += 1;
        			if(tot == words.size())
        				res.push_back(st);
        		}
        		else
        		{
        			w_map.clear();
        			st = ind+l;
        			tot = 0;
        		}
        		ind += l;
        	}
        }
        return res;
    }
    
};