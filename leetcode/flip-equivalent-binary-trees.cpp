// https://leetcode.com/problems/flip-equivalent-binary-trees
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL)
            return root2 == NULL;
        if(root2 == NULL) return false;
        
        if(root1->val != root2->val) return false;
        
        bool ans = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        ans = ans || flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right);
        return ans;
    }
};