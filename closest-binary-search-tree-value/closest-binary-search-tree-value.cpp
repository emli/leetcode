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
    int closestValue(TreeNode* root, double target) {
        int ans = -1;
        
        while(root != nullptr){
            cout <<"root = "<< root -> val << endl;
            double x = abs(double(root -> val) - target);
            if (ans == -1 || abs((double(ans) - target)) - x > 0){
                ans = root -> val;
            }
            
            if (double(root -> val) - target > 0){
                root = root -> left;
            }else {
                root = root -> right;
            }
        }
        
        return ans;
    }
};