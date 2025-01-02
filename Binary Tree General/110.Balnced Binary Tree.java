#define add2p(P, SZ, N, V) do { \
    if (SZ == N) { \
        SZ *= 2; \
        P = realloc(P, SZ * sizeof(int)); \
        // assert(P); // Uncomment to ensure P is not NULL after realloc \
    } \
    (P)[(N)++] = V; \
} while (0)

// In-order traversal function (iterative version with stack)
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int sz = 100; // Initial size for the result array
    int n = 0; // Number of elements in the result array
    int* p = malloc(sz * sizeof(int)); // Allocate memory for result array
    // assert(p); // Uncomment to ensure p is not NULL after malloc

    struct TreeNode** stack; // Stack for the iterative traversal
    int ssz = 100; // Initial size of the stack
    stack = malloc(ssz * sizeof(struct TreeNode*)); // Allocate memory for stack
    // assert(stack); // Uncomment to ensure stack is not NULL after malloc

    int sp = 0; // Stack pointer
    struct TreeNode* node = root; // Current node

    // Iterative in-order traversal
    while (node || sp) {
        // Traverse to the leftmost node
        while (node) {
            if (sp == ssz) { // If the stack is full, resize it
                ssz *= 2;
                stack = realloc(stack, ssz * sizeof(struct TreeNode*));
                // assert(stack); // Uncomment to ensure stack is not NULL after realloc
            }
            stack[sp++] = node; // Push node onto stack
            node = node->left; // Move to the left child
        }

        // Pop a node from the stack and process it
        node = stack[--sp];
        add2p(p, sz, n, node->val); // Add the node value to the result array

        // Move to the right child
        node = node->right;
    }

    // Free the stack memory
    free(stack);

    *returnSize = n; // Set the return size
    return p; // Return the result array
}