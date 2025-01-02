struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    struct ListNode* curr = head;
    int length = 0;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    int middle = length / 2;
    curr = head;
    for (int i = 0; i < middle - 1; i++) {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
}