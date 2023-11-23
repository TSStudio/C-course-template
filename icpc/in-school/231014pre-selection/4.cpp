#include <cstdio>

int a[100005], lx[100005], rx[100005], dx[100005];
;
bool optimized2 = false;

long long s1[100005], s2[2][50005];
long long sum(int l, int r, int d) {
    long long ans = 0;
    if (d == 1)
        return s1[r] - s1[l - 1];
    if (optimized2 && d == 2) {
        if (l & 1) {
            return s2[0][(r + 1) / 2] - s2[0][(l + 1) / 2 - 1];
        } else {
            return s2[1][r / 2] - s2[1][l / 2 - 1];
        }
    }
    for (int i = l; i <= r; i += d) {
        ans += a[i];
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s1[i] = s1[i - 1] + a[i];
    }
    int s2a = 0;
    int Q = q;
    while (Q--) {
        scanf("%d%d%d", &lx[Q], &rx[Q], &dx[Q]);
        if (dx[Q] == 2) {
            s2a++;
        }
    }
    if (s2a >= 5000) {
        optimized2 = true;
        for (int i = 1; i <= n; ++i) {
            s1[i] = s1[i - 1] + a[i];
            if (i & 1)
                s2[0][(i + 1) / 2] = s2[0][(i + 1) / 2 - 1] + a[i];
            else
                s2[1][i / 2] = s2[1][i / 2 - 1] + a[i];
        }
    }
    Q = q;
    while (Q--) {
        printf("%lld\n", sum(lx[Q], rx[Q], dx[Q]));
    }
    return 0;
}