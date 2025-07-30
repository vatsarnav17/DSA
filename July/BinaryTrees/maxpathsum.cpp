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
    int maxdown(TreeNode* root,int& maxi){
        if(root==NULL) return 0;
        int l = max(0,maxdown(root->left,maxi));
        int r = max(0,maxdown(root->right,maxi));
        maxi = max(maxi,l+r+root->val);
        return max(l,r) +root->val;

    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxdown(root,maxi);
        return maxi;
    }
};