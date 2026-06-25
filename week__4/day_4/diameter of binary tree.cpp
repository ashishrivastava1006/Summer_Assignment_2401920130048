
class Solution {
public:
int height(TreeNode* root){
    if (root== NULL){
    return 0;
}
int leftheight=height(root->left);
int rightheight=height(root->right);
return max(leftheight,rightheight)+1;}
    int diameterOfBinaryTree(TreeNode* root) {
if (root== NULL){
    return 0;
}    
int leftdiameter=diameterOfBinaryTree(root->left);
int rightdiameter=diameterOfBinaryTree(root->right);
int currdiameter= height(root->left)+height(root->right);
return max(currdiameter,max(leftdiameter,rightdiameter));

    }
};
