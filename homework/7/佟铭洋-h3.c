int majorityElement(int* nums, int numsSize) {  //模板题，维护众数
    int i = nums[0], j = 0;
    for (int k = 0; k < numsSize; k++) {
        if (nums[k] == i) {
            j++;
        } else {
            j--;
        }
        if (j < 0) {
            i = nums[k];
            j = 0;
        }
    }
    return i;
}