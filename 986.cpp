class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int l1 = A.size();
        int l2 = B.size();
        if(l1 == 0) return A;
        if(l2 == 0) return B;
        
        
        int cur_a = 0;
        int cur_b = 0;
        while(cur_a < l1 && cur_b < l2)
        {
            //not insert
            if(A[cur_a][1] < B[cur_b][0])
            {
                cur_a ++;
                continue;
            }
            if(B[cur_b][1] < A[cur_a][0])
            {
                cur_b ++;
                continue;
            }
            //insert
            if(A[cur_a][0] <= B[cur_b][0])
            {
                //partly insert
                if(A[cur_a][1] < B[cur_b][1])
                {
                    res.push_back(vector<int>({B[cur_b][0],A[cur_a][1]}));
                    cur_a ++;
                }
                //totally insert
                else
                {
                    res.push_back(B[cur_b]);
                    cur_b ++;
                }
            }
            else
            {
                //partly insert
                if(B[cur_b][1] < A[cur_a][1])
                {
                    res.push_back(vector<int>({A[cur_a][0],B[cur_b][1]}));
                    cur_b ++;
                }
                //totally insert
                else
                {
                    res.push_back(A[cur_a]);
                    cur_a ++;
                }
            }
            
        }
        return res;
    }
};