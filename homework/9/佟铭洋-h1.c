#include <stdio.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * matrixSize * matrixColSize[0]);
    int upper_limit = 0, lower_limit = matrixSize - 1, left_limit = 0, right_limit = matrixColSize[0] - 1;
    int i = 0, j = 0, k = 0;
    while (upper_limit <= lower_limit && left_limit <= right_limit) {
        for (j = left_limit; j <= right_limit; j++) {
            result[k++] = matrix[upper_limit][j];
        }
        upper_limit++;
        for (i = upper_limit; i <= lower_limit; i++) {
            result[k++] = matrix[i][right_limit];
        }
        right_limit--;
        if (upper_limit <= lower_limit) {
            for (j = right_limit; j >= left_limit; j--) {
                result[k++] = matrix[lower_limit][j];
            }
            lower_limit--;
        }
        if (left_limit <= right_limit) {
            for (i = lower_limit; i >= upper_limit; i--) {
                result[k++] = matrix[i][left_limit];
            }
            left_limit++;
        }
    }
    *returnSize = k;
    return result;
}