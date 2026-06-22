/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelTraversal;
    void levelOrderTraversal(TreeNode* root)
    {
        if(!root) return ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> level;
            for(int i=0;i<sz;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node)
                {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(!level.empty())
                levelTraversal.push_back(level);
        }
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        levelOrderTraversal(root);
        for(auto& i : levelTraversal)
        {
            res.push_back(i.back());
        }    
        return res;
    }
};