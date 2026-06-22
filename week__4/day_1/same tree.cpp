 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
   if(p==NULL||q==NULL){
    return p==q;
   }
   bool isrightsame =isSameTree(p->right,q->right);
   bool isleftsame =isSameTree(p->left,q->left);
   return isleftsame && isrightsame && p->val == q->val;
    }
};
