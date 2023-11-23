void permuteRecursive(int* nums, int numsSize, int** result, int* returnSize, int** returnColumnSizes, int* selectedSequence, int selectedCount, int* selected) {
    if (selectedCount == numsSize) {
        result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = selectedSequence[i];
        }
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (selected[i]) {
            continue;
        }
        selected[i] = 1;
        selectedSequence[selectedCount] = nums[i];
        permuteRecursive(nums, numsSize, result, returnSize, returnColumnSizes, selectedSequence, selectedCount + 1, selected);
        selected[i] = 0;
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 720);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 720);
    *returnSize = 0;
    int* selectedSequence = (int*)malloc(sizeof(int) * numsSize);
    int* selected = (int*)malloc(sizeof(int) * numsSize);
    memset(selected, 0, sizeof(int) * numsSize);
    permuteRecursive(nums, numsSize, result, returnSize, returnColumnSizes, selectedSequence, 0, selected);
    return result;
}
