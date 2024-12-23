struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *p, *q = NULL; // Initialize q to NULL
    int s = 0;

    while (l1 || l2 || s != 0) {
        p = malloc(sizeof(struct ListNode));
        if (!p) {
            return NULL;
        }
        if (l1) {
            s += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            s += l2->val;
            l2 = l2->next;
        }
        p->val = s % 10;
        p->next = NULL;
        s = s / 10;

        if (!head) {
            head = p;
        }
        if (q) {
            q->next = p;
        }
        q = p;
    }

    return head;
}