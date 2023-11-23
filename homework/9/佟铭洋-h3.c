// #include <stdio.h>
#ifdef DEBUG
#include "uthash.h"
#endif
// #include <stdbool.h>
//!!!! this program need uthash.h which is included in the leetcode platform

typedef struct hash_entry* hash_ptr;
typedef struct hash_entry hash_entry;
typedef struct entry entry;

struct hash_entry {
    int key;
    int val;
    UT_hash_handle hh;
};

struct entry {
    int first;
    int second;
};

void swap_entry(entry* a, entry* b) {
    entry t = *a;
    *a = *b, *b = t;
}

void sort(struct entry* entries, int begin, int end, int* ret, int* retSize, int k) {
    // Quick sort
    int base = rand() % (end - begin + 1) + begin;
    swap_entry(&entries[begin], &entries[base]);
    int pivot = entries[begin].second;
    int index = begin;
    for (int i = begin + 1; i <= end; ++i) {
        if (entries[i].second >= pivot) {
            swap_entry(&entries[++index], &entries[i]);
        }
    }
    swap_entry(&entries[begin], &entries[index]);
    if (k <= index - begin) {
        // need to sort the left part, the top k frequent elements are in the left part
        sort(entries, begin, index - 1, ret, retSize, k);
    } else {
        for (int i = begin; i <= index; ++i) {
            // as we are sure the first index-begin+1 elements are the top frequent elements
            ret[(*retSize)++] = entries[i].first;
        }
        if (k > index - begin + 1) {
            // still need to sort the right part, rest of the top k frequent elements are in the right part
            sort(entries, index + 1, end, ret, retSize, k - (index - begin + 1));
        }
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    hash_ptr h = NULL, p = NULL, tmp = NULL;
    // To count the frequency of each number
    for (int i = 0; i < numsSize; ++i) {
        HASH_FIND_INT(h, &nums[i], p);
        if (p == NULL) {
            p = malloc(sizeof(hash_entry));
            p->key = nums[i];
            p->val = 1;
            HASH_ADD_INT(h, key, p);
        } else {
            p->val++;
        }
    }
    entry entries[numsSize];
    int i = 0;
    HASH_ITER(hh, h, p, tmp) {
        entries[i].first = p->key;
        entries[i++].second = p->val;
    }
    int* ret = malloc(sizeof(int) * k);
    *returnSize = 0;
    sort(entries, 0, i - 1, ret, returnSize, k);
    return ret;
}