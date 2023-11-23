#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* nth = nullptr;
        for (int i = 1; i < n; i++) {
            cur = cur->next;
        }
        nth = head;
        while (cur->next != nullptr) {
            prev = nth;
            nth = nth->next;
            cur = cur->next;
        }
        if (prev == nullptr) {
            head = nth->next;
        } else {
            prev->next = nth->next;
        }
        return head;
    }
};