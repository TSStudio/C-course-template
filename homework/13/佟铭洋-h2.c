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
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* cur = head->next;
    struct ListNode* pre = head;
    int preVal = head->val;
    while (cur != NULL) {
        if (cur->val != preVal) {
            pre->next = cur;
            pre = cur;
            preVal = cur->val;
        }
        cur = cur->next;
    }
    pre->next = NULL;
    return head;
}