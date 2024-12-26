bool hasCycle(struct ListNode *head) {
    struct ListNode *n, *nn;

    if (!head) return false;

    n = nn = head;
    do {
        n = n->next;
        nn = nn->next;
        if (nn) nn = nn->next;
    } while (nn && n && n != nn);

    return nn != NULL;
}