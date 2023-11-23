#include <cstdio>
#include <cstring>

template <typename T>
inline T max(T a, T b) { return a > b ? a : b; }
template <typename T>
inline T min(T a, T b) { return a < b ? a : b; }

int a[200005], maxh;
bool isTop[200005];
int n, k_0;
int f[200005];

int IWillFinallyGoToTheTopWithIn(int from, int r) {
    if (f[from] != 0x3f3f3f3f) {
        printf("optimized %d\n", from);
        return f[from];
    }
    if (isTop[from]) return 0;
    int curHighestIndex = 0, curHighestValue = 0;
    for (int i = from; i >= max(1, from - r); --i) {
        if (a[i] == -1) break;
        if (a[i] >= curHighestValue) {
            curHighestValue = a[i];
            curHighestIndex = i;
        }
    }
    for (int i = from; i <= min(n, from + r); ++i) {
        if (a[i] == -1) break;
        if (a[i] > curHighestValue) {
            curHighestValue = a[i];
            curHighestIndex = i;
        }
    }
    if (curHighestValue == 0 || curHighestValue == a[from]) {
        f[from] = -1;
        return -1;
    }
    int ans = IWillFinallyGoToTheTopWithIn(curHighestIndex, r);
    f[from] = ans == -1 ? -1 : ans + 1;
    return ans == -1 ? -1 : ans + 1;
}

bool isOk(int answer_r) {
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) continue;
        int ans = IWillFinallyGoToTheTopWithIn(i, answer_r);
        if (ans == -1 || ans > k_0) return false;
    }
    return true;
}
int binSearchAnswer() {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (isOk(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
#ifdef DEBUG
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k_0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        maxh = maxh > a[i] ? maxh : a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == maxh) isTop[i] = true;
    }
    int ans = binSearchAnswer();
    if (ans < n) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}