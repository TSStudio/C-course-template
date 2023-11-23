/**
 * @param {int[]} digits
 * @param {int} digitsSize
 * @param {int*} returnSize
 * @return {int*} result
 * @note result的内存空间需要在函数外释放
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (digitsSize + 1));
    digits[digitsSize - 1]++;
    int i, flag = 0;  // flag: if true, then the first digit is 1
    for (i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] >= 10) {
            digits[i] -= 10;
            if (i == 0) {
                flag = 1;
            } else {
                digits[i - 1]++;
            }
        }
    }
    if (flag) {
        *returnSize = digitsSize + 1;
        result[0] = 1;
        for (i = 0; i < digitsSize; i++) {
            result[i + 1] = digits[i];
        }
    } else {
        *returnSize = digitsSize;
        for (i = 0; i < digitsSize; i++) {
            result[i] = digits[i];
        }
    }
    return result;
}