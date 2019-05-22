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
    void smallestFromLeaf(TreeNode* root, string cur, string& res)
    {
        cur = string(1,'a'+root->val)+cur;
        if(root->left != NULL)
            smallestFromLeaf(root->left, cur, res);
        if(root->right != NULL)
            smallestFromLeaf(root->right, cur, res);
        if(root->left == root->right) 
        {
            if(res == "") res = cur;
            else res = (res < cur ? res : cur);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root == NULL) return "";
        string res;
        smallestFromLeaf(root, "", res);
        return res;
    }
};