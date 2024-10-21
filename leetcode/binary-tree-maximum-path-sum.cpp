// https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int g_max_path;
    
    int maxPathUtil(TreeNode *root){
        int ret = root->val;
        int l_sum=0,r_sum=0;
        if(root->left)
            l_sum=maxPathUtil(root->left);
        if(root->right)
            r_sum=maxPathUtil(root->right);
        g_max_path = max(g_max_path, root->val+l_sum+r_sum);
        g_max_path = max(g_max_path, root->val+l_sum);
        g_max_path = max(g_max_path, root->val+r_sum);
        g_max_path = max(g_max_path, root->val);
        ret = max(ret, root->val+l_sum);
        ret = max(ret, root->val+r_sum);
        return ret;
    }
    
    int maxPathSum(TreeNode* root) {
        g_max_path=INT_MIN;
        maxPathUtil(root);
        return g_max_path;
    }
};
