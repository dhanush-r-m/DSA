class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
       Map<TreeNode, Integer> map = new HashMap<>();
       Stack<TreeNode> stack = new Stack<>();
       int diameter = 0;

       if(root != null){
            stack.push(root);
       }
       while (!stack.isEmpty()) {
            TreeNode node = stack.peek();
        
        if(node.left != null && !map.containsKey(node.left)) {
            stack.push(node.left);
        }
        else if
            (node.right != null && !map.containsKey(node.right)){
                stack.push(node.right);
            } else{
                stack.pop();
                int leftDepth = map.getOrDefault(node.left,0);
                int rightDepth = map.getOrDefault(node.right,0);

                map.put(node,1+Math.max(leftDepth,rightDepth));

                diameter = Math.max(diameter , leftDepth + rightDepth);
            }

        
       }
       return diameter;


    }
}