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
using ll = long long;
class Solution {
public:
    int levelOrderSearch(TreeNode* root)
    {
        if(!root) return 0;
        queue<pair<TreeNode*,ll>> q;
        ll max_width = -1e9;
        q.push({root , 0});
        while(!q.empty())
        {
            ll n = q.size();
            ll l = q.front().second;
            ll r = q.back().second;
            max_width = max(max_width , r-l+1);
            while(n--)
            {
                TreeNode* node = q.front().first;
                ll idx = q.front().second -l;
                q.pop();
                if(node->left)
                    q.push({node->left , 2*idx+1});
                if(node->right)
                    q.push({node->right , 2*idx+2});
            }
        }
        return (int)max_width;
    }    
    int widthOfBinaryTree(TreeNode* root) 
    {
        return levelOrderSearch(root);    
    }
};