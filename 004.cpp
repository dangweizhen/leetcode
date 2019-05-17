class Solution {
public:
	double find_k_th(vector<int>& nums1, vector<int>& nums2, int st1, int ed1, int st2, int ed2, int k)
	{
		int l1 = ed1-st1;
		int l2 = ed2-st2;
		if(l1 == 0)
			return nums2[st2+k];
		if(l2 == 0)
			return nums1[st1+k];
		if(l1 == 1 && l2 == 1)
        	return k ? max(nums1[st1],nums2[st2]) : min(nums1[st1],nums2[st2]);
		int mid1 = nums1[st1+l1/2];
		int mid2 = nums2[st2+l2/2];
		if(mid1 == mid2)
		{
			if(k < l1/2+l2/2)
				return find_k_th(nums1,nums2,st1,st1+l1/2,st2,st2+l2/2,k);
			else
				return find_k_th(nums1,nums2,st1+l1/2,ed1,st2+l2/2,ed2,k-l1/2-l2/2);
		}
		if(mid1 > mid2)
		{
			if(k < l1/2+l2/2)
				return find_k_th(nums1,nums2,st1,st1+l1/2,st2,ed2,k);
			if(k > l1/2+l2/2)
				return find_k_th(nums1,nums2,st1,ed1,st2+l2/2+1,ed2,k-l2/2-1);
			else
			{
				if(l1 == 1 || nums1[st1+l1/2-1] <= mid2) return mid2;
				else return find_k_th(nums1,nums2,st1,st1+l1/2,st2+l2/2+1,ed2,k-l2/2-1);
			}
		}
		if(mid1 < mid2)
		{
			if(k < l1/2+l2/2)
				return find_k_th(nums1,nums2,st1,ed1,st2,st2+l2/2,k);
			if(k > l1/2+l2/2)
				return find_k_th(nums1,nums2,st1+l1/2+1,ed1,st2,ed2,k-l1/2-1);
			else
			{
				if(l2 == 1 || nums2[st2+l2/2-1]<=mid1) return mid1;
				else return find_k_th(nums1,nums2,st1+l1/2+1,ed1,st2,st2+l2/2,k-l1/2-1);
			}
		}
		return 0;
	}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        if((l1+l2)%2)
        	return find_k_th(nums1,nums2,0,l1,0,l2,(l1+l2)/2);
        else
        	return (find_k_th(nums1,nums2,0,l1,0,l2,(l1+l2)/2)+find_k_th(nums1,nums2,0,l1,0,l2,(l1+l2)/2-1))/2;
    }
};
