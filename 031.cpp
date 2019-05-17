class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        vector<int>::iterator ed = nums.end()-1;
        for(; ed != nums.begin(); ed --)
        {
        	if((*ed) > *(ed-1))
        	{
                //cout << *ed << " ";
        		int tmp = *(ed-1);
        		for(vector<int>::iterator it = nums.end()-1;it != (ed-1);it--)
                {
                    if(*it > *(ed-1))
                    {
                        *(ed-1)=*it;
                        *it = tmp;
                        break;
                    }
                }
                break;
        	}
        }
        sort(ed, nums.end());
    }
};