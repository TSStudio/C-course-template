#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char* convertToBase7(int num) {
    if (num == 0) {
        return "0";
    }
    int count = 0;
    int t = abs(num);
    int b = abs(num);
    char* a = (char*)malloc(100 * sizeof(char));
    memset(a, 0, sizeof(a));
    while (b > 6) {
        b = b / 7;
        count++;
    }
    if (num > 0) {
        for (int i = count; i >= 0; i--) {
            a[i] = t % 7 + '0';
            if (i >= 100) {
                printf("Array out of bound\n");
            }
            t = t / 7;
        }
        a[count + 1] = '\0';
        return a;
    }
    a[0] = '-';
    for (int i = count + 1; i >= 1; i--) {
        a[i] = t % 7 + '0';
        if (i >= 100) {
            printf("Array out of bound\n");
        }
        t = t / 7;
    }
    a[count + 2] = '\0';
    if (count + 2 >= 100) {
        printf("Array out of bound\n");
    }
    return a;
}
int main() {
    int i = 2342343;
    char* a = convertToBase7(i);
    printf("%s\n", a);
    getchar();
    return 0;
}