#define INT_MIN_M1 -2147483649LL
int thirdMax(int* nums, int numsSize) {  //模板题，维护前三大
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
    long long firstMax = INT_MIN_M1, secondMax = INT_MIN_M1, thirdMax = INT_MIN_M1;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = nums[i];
        } else if (nums[i] > secondMax && nums[i] < firstMax) {
            thirdMax = secondMax;
            secondMax = nums[i];
        } else if (nums[i] > thirdMax && nums[i] < secondMax) {
            thirdMax = nums[i];
        }
    }
    return thirdMax == INT_MIN_M1 ? (int)firstMax : (int)thirdMax;
}