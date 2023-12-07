#ifdef DEBUG
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
#endif
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    int len = 0;
    struct ListNode* cur = head;
    while (cur->next != NULL) {
        len++;
        cur = cur->next;
    }
    len++;
    k %= len;
    if (k == 0) {
        return head;
    }
    cur->next = head;
    //find the last kth node
    cur = head;
    for (int i = 0; i < len - k - 1; i++) {
        cur = cur->next;
    }
    struct ListNode* newHead = cur->next;
    cur->next = NULL;
    return newHead;
}