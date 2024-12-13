class Solution {
public:

    void inorder(TreeNode* root, vector<int>&v){
        if(root!=NULL){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);  
        }else{
            v.push_back(10000);
        }
    }

    void preorder(TreeNode* root, vector<int>&v){
        if(root!=NULL){
            v.push_back(root->val);
            preorder(root->left,v);
            preorder(root->right,v);  
        }else{
            v.push_back(10000);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> inp,inq,preq,prep;
        inorder(p,inp);
        inorder(q,inq);

        preorder(p,prep);
        preorder(q,preq);

        if(inp==inq && prep==preq)
            return true;
        else
            return false;
        
    }
};