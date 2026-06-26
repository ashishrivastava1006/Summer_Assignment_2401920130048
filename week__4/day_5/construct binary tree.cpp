#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Validation: If arrays have different sizes, tree construction is invalid
        if (preorder.size() != inorder.size()) 
            return nullptr;

        int n = inorder.size();
        // Caching inorder indices using an unordered_map for O(1) average lookups
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, n - 1, inorder, 0, n - 1, map);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd,
                              unordered_map<int, int>& map) {
        // Base case: Pointers crossing denotes an empty subtree segment
        if (preStart > preEnd || inStart > inEnd) 
            return nullptr;

        // Extract root from the beginning of the current preorder sequence
        int rootVal = preorder[preStart];
        TreeNode* rootNode = new TreeNode(rootVal);

        // Fetch index of the root in the inorder mapping
        int inPos = map[rootVal];
        // Calculate the count of elements in the left subtree partition
        int leftTotal = inPos - inStart;

        // Recursive sub-division for left and right children
        rootNode->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTotal,
                                         inorder, inStart, inPos - 1, map);
        rootNode->right = buildTreeHelper(preorder, preStart + leftTotal + 1, preEnd,
                                          inorder, inPos + 1, inEnd, map);

        return rootNode;
    }
};
