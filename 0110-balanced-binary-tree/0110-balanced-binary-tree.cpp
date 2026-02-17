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

    pair<int , bool> height(TreeNode* root){
        if(root==NULL) return {0,true};

        auto left=height(root->left);
        auto right=height(root->right);

        int h=1+max(left.first, right.first);

        bool isbal= left.second && right.second && abs(left.first-right.first)<=1;

        return {h,isbal};
    }
    bool isBalanced(TreeNode* root) {
        return height(root).second;
    }
};