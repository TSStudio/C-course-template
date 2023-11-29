int min(int a, int b) {
    return a < b ? a : b;
}

int minPathSum(int **grid, int gridSize, int *gridColSize) {
    int **dp = (int **)malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * gridColSize[0]);
    }
    dp[0][0] = grid[0][0];
    for (int i = 1; i < gridSize; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < gridColSize[0]; i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < gridColSize[0]; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[gridSize - 1][gridColSize[0] - 1];
}