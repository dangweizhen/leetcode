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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root->val < val)
        {
            newNode->left = root;
            return newNode;
        }
        TreeNode* lastNode = root;
        TreeNode* curNode = root->right;
        while(curNode != NULL)
        {
            if(curNode->val < val)
            {
                lastNode->right = newNode;
                newNode->left = curNode;
                return root;
            }
            lastNode = curNode;
            curNode = curNode->right;
        }
        lastNode->right = newNode;
        return root;
    }
};