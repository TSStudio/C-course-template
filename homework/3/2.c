#include<stdio.h>
// Copyright Tong Mingyang 2023. All Rights Reserved.
// Module: homework/20230920/2
// This file is licensed under the MIT License.
// License text available at https://opensource.org/licenses/MIT
void ToBinary(int n, int* len, int* digit) {
    int i = 0;
    while (n > 0) {
        *(digit + i) = n % 2;
        n /= 2;
        i++;
    }
    *len = i;
}
int main(void){
    int n;
    int len;
    int digit[32];
    scanf("%d", &n);
    ToBinary(n, &len, digit);
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", digit[i]);
    }
    printf("\n%d\n", len);
    getchar();getchar();
    return 0;
}