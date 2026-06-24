/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root) {
            if(p->val < root->val && q->val < root->val) // both are smaller, goto left 
                root = root->left;
            else if(p->val > root->val && q->val > root->val) // both are larger, goto right
                root = root->right;
            else
                return root; 
        }

        return NULL;
        
    }
};
