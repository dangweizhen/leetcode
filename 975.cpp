class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2)
    {
        if(p1.first != p2.first) return p1.first < p2.first;
        else return p1.second < p2.second;
    }
    int oddEvenJumps(vector<int>& A) {
        int l = A.size();
        if(l <= 1) return l;
        vector<pair<int, int>> record;
        for(int i = 0;i < l;i ++)
            record.push_back(make_pair(A[i],i));
        sort(record.begin(),record.end(),cmp);
        vector<int> odd_next(l,-1);
        vector<int> even_next(l,-1);
        stack<int> stack1; //record max value less, even target
        stack<int> stack2; //record min value larger, odd target
        vector<bool> odd_access(l,false);
        vector<bool> even_access(l,false);
        int cur = 0;
        while(cur < l)
        {
            int ed;
            for(ed = cur+1;ed < l;ed ++)
            {
                if(record[ed].first != record[ed-1].first)
                    break;
            }
            for(int i = ed-1;i >= cur;i --)
            {
                while(!stack1.empty() && stack1.top() < record[i].second)
                {
                    stack1.pop();
                }
                if(!stack1.empty())
                {
                    even_next[record[i].second] = stack1.top();
                }
                stack1.push(record[i].second);
            }
            cur = ed;
        }
        for(int i = l-1;i >= 0;i --)
        {
            while(!stack2.empty() && stack2.top() < record[i].second)
            {
                stack2.pop();
            }
            if(!stack2.empty())
            {
                odd_next[record[i].second] = stack2.top();
            }
            stack2.push(record[i].second);
        }
        odd_access[l-1] = true;
        even_access[l-1] = true;
        int res = 1;
        
        for(int i = l-2;i >= 0;i --)
        {
            if(odd_next[i] != -1)
            {
                odd_access[i] = even_access[odd_next[i]];
            }
            if(even_next[i] != -1)
            {
                even_access[i] = odd_access[even_next[i]];
            }
            if(odd_access[i]) 
            {
                res ++;
                //cout << i << " " ;
            }
        }
        return res;
    }
};