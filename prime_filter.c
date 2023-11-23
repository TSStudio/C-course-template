#include <stdio.h>
#include <stdbool.h>

int maxN;
bool isNotPrime[1000000005];
int Prime[80000005], cnt = 0;

void filter() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i <= maxN; i++) {
        if (!isNotPrime[i]) {
            Prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * Prime[j] <= maxN; j++) {
            isNotPrime[i * Prime[j]] = true;
            if (i % Prime[j] == 0) {
                break;
            }
        }
    }
}
int main() {
    scanf("%d", &maxN);
    filter();
    printf("%d\n", cnt);
    getchar();
    getchar();
    return 0;
}