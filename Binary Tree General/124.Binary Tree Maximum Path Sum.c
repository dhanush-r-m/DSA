int maxsum(struct TreeNode *node, int *max) {
    int l, r, k, s;
    
    if (!node) return 0;
    
    l = maxsum(node->left, max);
    r = maxsum(node->right, max);
    
    l = l > 0 ? l : 0;                  // ignore negative
    r = r > 0 ? r : 0;
    
    s = node->val + l + r;              // current node + both sides
    if (*max < s) *max = s;
    
    k = node->val + (l > r ? l : r);    // current node + one side only
    return k;
}
int maxPathSum(struct TreeNode* root) {
    int max;
    if (root) {
        max = root->val;
        maxsum(root, &max);
    } else {
        max = 0;
    }
    return max;
}