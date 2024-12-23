struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head, *p;

    head.next = NULL; // Initialize the dummy node's next pointer
    p = &head;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    if (l1) p->next = l1;
    if (l2) p->next = l2;

    return head.next;
}
