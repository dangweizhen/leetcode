class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1;i < n;i ++)
        {
            string tmp="";
            int k = 0;
            while(k < res.length())
            {
                for(int j = 0;j+k <= res.length();j ++)
                {
                    if(j+k == res.length() || res[j+k] != res[k])
                    {
                        //tmp=tmp+(char)('0'+j)+res[k];
                        tmp.append(1,'0'+j);
                        tmp.append(1,res[k]);
                        k=j+k;
                        break;
                    }
                }
            }
            //cout << res<< " ";
            res = tmp;
        }
        return res;
    }
};