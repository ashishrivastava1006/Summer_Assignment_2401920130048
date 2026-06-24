class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;

        while (node) {
            int num = node->val;

            if (num == val)
                return node;

            if (num > val)
                node = node->left;
            else
                node = node->right;
        }

        return nullptr;
    }
};
