/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flipMatchVoyage(TreeNode* root, vector<int>& voyage, int& cur, vector<int>& res, int& l)
    {
        if(root == NULL) return true;
        if(cur >= voyage.size()) return false;
        if(root->val != voyage[cur]) return false;
        int t1 = cur;
        int t2 = l;
        cur ++;
        if(flipMatchVoyage(root->left, voyage, cur, res, l))
        {
            if(flipMatchVoyage(root->right, voyage, cur, res, l))
                return true;
        }
        cur = t1;
        l = t2;
        cur ++;
        res[l] = root->val;
        l ++;
        if(flipMatchVoyage(root->right, voyage, cur, res, l))
        {
            if(flipMatchVoyage(root->left, voyage, cur, res, l))
                return true;
        }
        return false;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res(1001,0);
        vector<int> ans;
        int final_v = 0;
        int final_l = 0;
        if(!flipMatchVoyage(root, voyage, final_v, res, final_l))
            return vector<int>(1,-1);
        else
        {
            if(final_v != voyage.size())
                return vector<int>(1,-1);
            for(int i = 0;i < final_l; i++)
                ans.push_back(res[i]);
            return ans;
        }
        return res;
    }
};