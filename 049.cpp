class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int l = strs.size();
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;
        if(l == 0) return res;
        for(int i = 0;i < l;i ++)
        {
            int letter[26]={0};
            for(int j = 0;j < strs[i].length();j ++)
                letter[(int)(strs[i][j]-'a')]+=1;
            string w="";
            for(int j = 0;j < 26;j ++)
            {
                if(letter[j] > 0)
                {
                    string tmp(letter[j],'a'+j);
                    w.append(tmp);
                }
            }
            if(m.find(w) != m.end())
                m[w].push_back(strs[i]);
            else
            {
                vector<string> v(1,strs[i]);
                m[w]=v;
            }
        }
        
        for(unordered_map<string,vector<string>>::iterator it=m.begin();it!=m.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};