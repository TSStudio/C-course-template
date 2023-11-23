void moveZeroes(int* nums, int numsSize) {
    int i = 0, j = 0;  //i为慢指针，j为快指针
    for (j = 0; j < numsSize; j++) {
        if (nums[j] != 0) {
            int temp;
            temp = nums[i];  //swap
            nums[i++] = nums[j];
            nums[j] = temp;
        }
    }
}