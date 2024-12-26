class Solution {
    public boolean hasPathSum(TreeNode root, int Sum) {
        if(root == null){
            return false;
        }
        Stack<TreeNode> path = new Stack<>();
        Stack<Integer> sumpath = new Stack<>();

        path.push(root);
        sumpath.push(root.val);

        while(!path.isEmpty()){
            TreeNode temp = path.pop();
            int tempval = sumpath.pop();

            if(temp.right==null && temp.left==null && tempval == Sum)
                return true;
            
            if(temp.right!=null){
                path.push(temp.right);
                sumpath.push(temp.right.val + tempval);
            }
            if(temp.left!=null){
                path.push(temp.left);
                sumpath.push(temp.left.val + tempval);
            }
        }
        return false;
    }
}