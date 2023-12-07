#include <stdio.h>

void swap(int** a, int** b) {
    int* tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int arr[10] = {9, 3, 2, 7, 6, 4, 1, 0, 5, 8};
    int* p[10];
    for (int i = 0; i < 10; i++) {
        p[i] = &arr[i];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (*p[j] > *p[j + 1]) {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", *p[i]);
    }
    printf("\n");
    getchar();
    getchar();
    return 0;
}