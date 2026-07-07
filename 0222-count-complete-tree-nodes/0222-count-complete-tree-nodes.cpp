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
    int countLeft(TreeNode* root)
    {
        int cnt = 0;
        while(root != NULL)
        {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int countRight(TreeNode* root)
    {
        int cnt = 0;
        while(root != NULL)
        {
            cnt++;
            root = root->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) 
    {
        if(!root) return 0;
        int leftHeight = countLeft(root);
        int rightHeight = countRight(root);
        if(leftHeight == rightHeight)
            return pow(2,leftHeight)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};