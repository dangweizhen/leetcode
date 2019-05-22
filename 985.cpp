class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        int l = A.size();
        vector<int> res;
        for(vector<int>::iterator it = A.begin();it != A.end();it ++)
            if(!((*it)%2)) sum += (*it);
        for(int i = 0;i < queries.size();i ++)
        {
            if(!(A[queries[i][1]]%2)) sum -= A[queries[i][1]];
            //cout << sum << " ";
            A[queries[i][1]] += queries[i][0];
            if(!(A[queries[i][1]]%2)) sum += A[queries[i][1]];
            res.push_back(sum);
        }
        return res;
    }
};