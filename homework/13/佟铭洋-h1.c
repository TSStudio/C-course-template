#ifdef DEBUG
#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct dynamic_array {
    int* data;
    int size;
    int capacity;
};
void init(struct dynamic_array* arr) {
    arr->data = (int*)malloc(sizeof(int) * 10);
    arr->size = 0;
    arr->capacity = 10;
}
void expand(struct dynamic_array* arr) {
    int* temp = (int*)malloc(sizeof(int) * arr->capacity * 2);
    for (int i = 0; i < arr->size; i++) {
        temp[i] = arr->data[i];
    }
    free(arr->data);
    arr->data = temp;
    arr->capacity *= 2;
}
void push_back(struct dynamic_array* arr, int val) {
    if (arr->size == arr->capacity) {
        expand(arr);
    }
    arr->data[arr->size++] = val;
}
typedef struct dynamic_array dynamic_array;
void travel(struct TreeNode* root, dynamic_array* arr) {
    if (root == NULL) {
        return;
    }
    travel(root->left, arr);
    push_back(arr, root->val);
    travel(root->right, arr);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    dynamic_array arr;
    init(&arr);
    travel(root, &arr);
    *returnSize = arr.size;
    return arr.data;
}