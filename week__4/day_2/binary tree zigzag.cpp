class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;

        }
        queue<TreeNode*>nodequeue;
        nodequeue.push(root);
        bool leftToright=true;
        while(!nodequeue.empty()){
            int size=nodequeue.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                TreeNode*node=nodequeue.front();
                nodequeue.pop();
                int index=(leftToright)?i:(size-1-i);
                row[index]=node->val;
                if(node->left){
                    nodequeue.push(node->left);}
                    if(node->right){
                    nodequeue.push(node->right);
                }
            }leftToright=!leftToright;
            result.push_back(row);
            }
            return result;
        
    }
};
