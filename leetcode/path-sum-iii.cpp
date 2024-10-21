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
    unordered_map<int,int> freq;
    int pathSum(TreeNode* root, int sum, int sum_till_now=0) {
        if(!freq[0]) freq[0]=1;
        if(!root) return 0;
        int ans=0;
        if(freq.find(sum_till_now+root->val-sum) != freq.end())
            ans+=freq[sum_till_now+root->val-sum];
        freq[sum_till_now+root->val]++;
        ans += pathSum(root->left, sum, sum_till_now+root->val);
        ans += pathSum(root->right, sum, sum_till_now+root->val);
        freq[sum_till_now+root->val]--;
        return ans;
    }
};
