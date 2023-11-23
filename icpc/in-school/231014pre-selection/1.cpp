#include <cstdio>

int main() {
#ifdef DEBUG
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    char a, b;
    bool ans;
    a = getchar();
    if (a == 'O')
        ans = true;
    else
        ans = false;
    while ((b = getchar()) != EOF) {
        if (b == '1') ans = !ans;
    }
    if (ans)
        printf("1");
    else
        printf("0");
    return 0;
}