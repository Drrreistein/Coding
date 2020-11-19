#pragma once
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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
class DiameterOfBinaryTree {
public:
    int ans=0;

    int depth(TreeNode* root) {
        if (!root) { return 0; }

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        ans = max(ans, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }
    int solu1(TreeNode* root) {
        if (!root) { return 0; }
        depth(root);
        return ans;
    }
};