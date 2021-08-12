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
    int findAns(TreeNode* node, int mx,int mn){
        if (node == nullptr){
            return mx - mn;
        }
        return max (
            findAns(node->left,max(mx,node->val),min(mn,node->val)),
            findAns(node->right,max(mx,node->val),min(mn,node->val)) 
        );
    } 
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return findAns(root, root->val, root->val);
    }
};