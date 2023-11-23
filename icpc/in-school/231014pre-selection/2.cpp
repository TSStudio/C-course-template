#include <cstdio>

int main() {
#ifdef DEBUG
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    unsigned long long n,
        s, t, x, y, a, b, ans = 0;

    scanf("%llu%llu%llu%llu%llu%llu%llu", &n, &s, &t, &x, &y, &a, &b);
    if (a < b && t < y * n) {
        if (s >= y * n - t) {
            s -= y * n - t;
            t = y * n;
        } else {
            t += s;
            s = 0;
        }
    }
    if (a > b && s > x * n) {
        t += s - x * n;
    }
    if (s < x * n) {
        ans += ((x * n) - s) * a;
    }
    if (t < y * n) {
        ans += ((y * n) - t) * b;
    }
    printf("%llu", ans);
    return 0;
}