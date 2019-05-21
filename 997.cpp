class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //sum of truster of person i
        vector<int> truster(N,0);
        //sum of trusted people of person i
        vector<int> trusted(N,0);
        for(vector<vector<int>>::iterator it = trust.begin(); it != trust.end();it ++)
        {
            truster[(*it)[1]-1] ++;
            trusted[(*it)[0]-1] ++;
        }
        for(int i = 0;i < N;i ++)
        {
            if(truster[i] == N-1 && trusted[i] == 0) return i+1;
        }
        return -1;
    }
};