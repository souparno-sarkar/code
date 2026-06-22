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
        if(!root) return;
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
                else
                    level.push_back(-1e9);
            }
            levelTraversal.push_back(level);
        }
    }
    bool isPalindrom(vector<int>& nums)
    {
        vector<int> rNums = nums;
        reverse(rNums.begin() , rNums.end());
        return (nums==rNums);
    }
    bool isSymmetric(TreeNode* root) 
    {
        levelOrderTraversal(root);
        for(auto& i : levelTraversal)
        {
            vector<int> temp(i.begin() , i.end());
            bool flag = isPalindrom(temp);
            if(!flag)
                return false;
        }
        return true;
    }
};