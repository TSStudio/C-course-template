#include <stdio.h>

int arr[2][2][2];

int main() {
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    printf("%p\n", &arr[i][j][k]);
    printf("%p\n", arr[i][j] + k);
    printf("%p\n", &((*(arr[i] + j))[k]));
    printf("%p\n", *(arr[i] + j) + k);
    printf("%p\n", &((*(*(arr + i) + j))[k]));
    printf("%p\n", *(*(arr + i) + j) + k);
    printf("%p\n", &((*(arr + i))[j][k]));
    printf("%p\n", (*(arr + i))[j] + k);
    getchar();
    getchar();
    return 0;
}