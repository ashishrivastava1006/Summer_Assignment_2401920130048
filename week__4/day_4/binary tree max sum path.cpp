class Solution {
public:
 
    int maxPathdown(TreeNode* node,int &maxi){
        if(node==NULL)return 0;
          int left=max(0,maxPathdown(node->left,maxi));
  int right=max(0,maxPathdown(node->right,maxi));
  maxi=max(maxi,left+right+node->val);
  return max(left,right)+node->val;
    }
int maxPathSum(TreeNode* root) {
     int maxi = INT_MIN;
       maxPathdown(root,maxi);
     return maxi;
    }
};
