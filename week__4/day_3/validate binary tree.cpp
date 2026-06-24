class Solution {
private:
    bool check(TreeNode* root, long long minimum, long long maximum) {
        if (!root) return true;

        int currVal = root->val;

        if (currVal >= maximum || currVal <= minimum)
            return false;

        return check(root->right, currVal, maximum) &&
               check(root->left, minimum, currVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
