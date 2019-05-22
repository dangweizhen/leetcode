class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26,-1);
        for(int i = 0;i < 26;i ++)
            parent[i] = i;
        for(vector<string>::iterator it = equations.begin();it != equations.end();it ++)
        {
            if((*it)[1] == '=')
            {
                int c1 = (*it)[0]-'a';
                int c2 = (*it)[3]-'a';
                //merge
                while(parent[c1] != c1)
                {
                    c1 = parent[c1];
                }
                while(c2 != parent[c2])
                {
                    c2 = parent[c2];
                }
                parent[c1] = c2;
            }
        }
        for(vector<string>::iterator it = equations.begin();it != equations.end();it ++)
        {
            if((*it)[1] == '!')
            {
                int c1 = (*it)[0]-'a';
                int c2 = (*it)[3]-'a';
                while(parent[c1] != c1)
                {
                    c1 = parent[c1];
                }
                while(c2 != parent[c2])
                {
                    c2 = parent[c2];
                }
                if(c1 == c2) return false;
            }
        }
        return true;
    }
};
