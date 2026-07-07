/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<int> res;
    unordered_map<TreeNode* , TreeNode*> parent;
    void inorderTraversal(TreeNode* root)
    {
        if(!root) return;
        if(root->left)
            parent[root->left] = root;
        inorderTraversal(root->left);
        if(root->right)
            parent[root->right] = root;
        inorderTraversal(root->right);
    }
    void levelOrderTraversal(TreeNode* target , int k)
    {
        queue<TreeNode*> q;
        unordered_set<int> visited;
        q.push(target);
        visited.insert(target->val);
        while(!q.empty())
        {
            int n = q.size();
            if(k == 0)
                break;
            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != NULL && !visited.count(curr->left->val))
                {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right != NULL && !visited.count(curr->right->val))
                {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if(parent[curr] != NULL && !visited.count(parent[curr]->val))
                {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        inorderTraversal(root);
        levelOrderTraversal(target , k);
        return res;
    }
};