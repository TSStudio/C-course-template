#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, a[500], b[500];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        b[i] = i;
    }
    //bubble sort a+1~a+n
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[b[j]] > a[b[j + 1]]) {
                swap(&b[j], &b[j + 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    int delta = 0;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && a[b[i]] == a[b[i - 1]]) delta++;
        printf("%d ", b[i] - delta);
    }
    getchar();
    getchar();

    return 0;
}