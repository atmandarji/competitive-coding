// https://leetcode.com/problems/delete-nodes-and-return-forest/submissions/
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del_set;
        for(int i=0;i<to_delete.size();i++)
            del_set.insert(to_delete[i]);
        queue<TreeNode*> q;
        vector<TreeNode*> ans;
        if(del_set.find(root->val)==del_set.end()) ans.push_back(root);
        q.push(root);
        while(!q.empty()){
            TreeNode *f = q.front();
            q.pop();
            if(f->left){
                q.push(f->left);
                if(del_set.find(f->left->val)!=del_set.end())
                    f->left=NULL;
            }
            if(f->right){
                q.push(f->right);
                if(del_set.find(f->right->val)!=del_set.end())
                    f->right=NULL;
            }
            if(del_set.find(f->val)!=del_set.end()){
                if(f->left) ans.push_back(f->left);
                if(f->right) ans.push_back(f->right);
            }
            
        }
        return ans;
    }
};