#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortColors(int* nums, int numsSize) {
    int i = 0, j = 0, k = numsSize - 1;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            swap(&nums[i], &nums[j]);
            j++;
        }
    }
    for (i = numsSize - 1; i >= j; i--) {
        if (nums[i] == 2) {
            swap(&nums[i], &nums[k]);
            k--;
        }
    }
}