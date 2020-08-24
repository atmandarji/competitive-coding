// https://leetcode.com/problems/path-sum-iii/submissions/
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
    int pathSum(TreeNode* root, int sum, bool con=false) {
        if(!root) return 0;
        int ans=0;
        if(root->val==sum)
            ans++;
        if(!con){
            ans += pathSum(root->left, sum);
            ans += pathSum(root->right, sum);
        }
        ans += pathSum(root->left, sum-root->val, true);
        ans += pathSum(root->right, sum-root->val, true);
        return ans;
    }
};
