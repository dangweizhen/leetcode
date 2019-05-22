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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y) return false;
        queue<pair<TreeNode*,int>> q;
        int x_d = -1;
        int y_d = -1;
        pair<TreeNode*,int> cur;
        q.push(make_pair(root, 0));
        while(!q.empty())
        {
            cur = q.front();
            TreeNode* cur_node = cur.first;
            int hit = 0;
            if(cur_node->left != NULL)
            {
                if(cur_node->left->val == x) 
                {
                    x_d = cur.second+1;
                    hit ++;
                }
                if(cur_node->left->val == y) 
                {
                    y_d = cur.second+1;
                    hit ++;
                }
                q.push(make_pair(cur_node->left, cur.second + 1));
            }
            if(cur_node->right != NULL)
            {
                if(cur_node->right->val == x) 
                {
                    x_d = cur.second+1;
                    hit ++;
                }
                if(cur_node->right->val == y) 
                {
                    y_d = cur.second+1;
                    hit ++;
                }
                q.push(make_pair(cur_node->right, cur.second + 1));
            }
            q.pop();
            if(x_d >= 0 && y_d >= 0) return (x_d == y_d && hit != 2);
        }
        return false;
    }
};