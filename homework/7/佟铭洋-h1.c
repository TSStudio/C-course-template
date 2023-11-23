int removeDuplicates(int* nums, int numsSize) {  //模板题，快慢指针
    int i = 0, j = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != nums[j]) {
            nums[++j] = nums[i];
        }
    }
    return j + 1;
}