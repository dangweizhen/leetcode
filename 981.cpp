class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<string, int>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(m.find(key) == m.end())
            m[key] = vector<pair<string, int>>();
        pair<string, int> p = make_pair(value, timestamp);
        m[key].push_back(p);
    }
    
    string get(string key, int timestamp) {
        //cout << key << endl;
        unordered_map<string, vector<pair<string, int>>>::iterator it = m.find(key);
        if(it == m.end())
        {
            return "";
        }
        else
        {
            int l = m[key].size();
            int st = 0;
            int ed = l-1;
            while(st <= ed)
            {
                int mid = (st+ed)/2;
                int t = m[key][mid].second;
                if(t > timestamp)
                {
                    ed = mid-1;
                }
                else
                {
                    if(t == timestamp || mid == l-1 || m[key][mid+1].second > timestamp)
                        return m[key][mid].first;
                    st = mid+1;
                }
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */