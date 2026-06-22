class Solution {
public:
    void solve(TreeNode* root, int &ans, int len) {
        if(!root) {
            ans = max(ans, len);
            return;
        }
        solve(root->left, ans, len+1);
        solve(root->right, ans, len+1);
    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        solve(root, ans, 0);
        return ans;
    }
};
