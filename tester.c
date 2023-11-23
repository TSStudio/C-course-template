#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanaf("%d%d", &n, &m);
    int** a = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}