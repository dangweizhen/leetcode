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
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0] != b[0]) return a[0] < b[0];
        if(a[1] != b[1]) return a[1] > b[1];
        return a[2] < b[2];
    }
    void DFS(TreeNode* root, int x, int y, vector<vector<int>>& t)
    {
        if(root->left != NULL)
            DFS(root->left, x-1, y-1, t);
        t.push_back(vector<int>({x,y,root->val}));
        if(root->right != NULL)
            DFS(root->right, x+1, y-1, t);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> tmp;
        vector<vector<int>> res;
        if(root == NULL) return res;
        DFS(root,0,0,tmp);
        sort(tmp.begin(), tmp.end(), cmp);
        int cur_x = tmp[0][0];
        vector<int> x;
        for(int i = 0;i < tmp.size(); i++)
        {
            if(cur_x == tmp[i][0])
                x.push_back(tmp[i][2]);
            else
            {
                res.push_back(x);
                x.clear();
                cur_x = tmp[i][0];
                x.push_back(tmp[i][2]);
            }
        }
        res.push_back(x);
        return res;
    }
};