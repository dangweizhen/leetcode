class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int l = days.size();
        if(l == 0) return 0;
        vector<int> min_cost(l,0);
        min_cost[0] = min(costs[0],min(costs[1],costs[2]));
        for(int i = 1;i < l;i ++)
        {
            //one day
            int c1 = costs[0] + min_cost[i-1];
            
            int j_w = i, j_m = i;
            while(j_w >= 0 && days[i]-days[j_w]<7)
            {
                j_w --;
            }
            j_m=j_w;
            while(j_m >= 0 && days[i]-days[j_m]<30)
            {
                j_m --;
            }
            //one week
            int c2 = costs[1]+(j_w < 0 ? 0 : min_cost[j_w]);
            //one month
            int c3 = costs[2]+(j_m < 0 ? 0 : min_cost[j_m]);
            min_cost[i] = min(c1,min(c2,c3));
        }
        return min_cost[l-1];
    }
};