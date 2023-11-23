#include <cstdio>
#include <cstring>
#include <cmath>

template <typename T>
inline T max(T a, T b) { return a > b ? a : b; }
template <typename T>
inline T min(T a, T b) { return a < b ? a : b; }

int a[200005], maxh, n, k_0;
int left[200005], right[200005], f[200005];
int to[200005];
struct mount {
    int index, height;
    bool operator>(const mount& rhs) const {
        return height == rhs.height ? index < rhs.index : height > rhs.height;
    }
} maxN[200005][20];
bool isTop[200005];

mount Query(int l, int r) {
    int k = log2(r - l + 1);
    return max(maxN[l][k], maxN[r - (1 << k) + 1][k]);
}

int IWillFinallyGoToTheTopWithIn(int from, int r) {
    if (f[from] != 0x3f3f3f3f) {
        return f[from];
    }
    if (isTop[from]) return 0;
    if (to[from] == from) {
        f[from] = -1;
        return -1;
    }
    int ans = IWillFinallyGoToTheTopWithIn(to[from], r);
    f[from] = ans == -1 ? -1 : ans + 1;
    return ans == -1 ? -1 : ans + 1;
}

bool isOk(int answer_r) {
    memset(f, 0x3f, sizeof(f));
    //printf("####r=%d\n", answer_r);
    int lastNotReachable = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            lastNotReachable = i;
            continue;
        }
        left[i] = max(lastNotReachable + 1, i - answer_r);
    }
    lastNotReachable = n + 1;
    for (int i = n; i >= 1; --i) {
        if (a[i] == -1) {
            lastNotReachable = i;
            continue;
        }
        right[i] = min(lastNotReachable - 1, i + answer_r);
    }
    for (int i = 1; i <= n; ++i) {
        to[i] = Query(left[i], right[i]).index;
        if (a[to[i]] == a[i]) to[i] = i;
        //printf("%d -> %d\n", i, to[i]);
    }
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
        maxN[i][0].index = i;
        maxN[i][0].height = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == maxh) isTop[i] = true;
    }
    for (int j = 1; j <= 19; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            maxN[i][j] = max(maxN[i][j - 1], maxN[i + (1 << (j - 1))][j - 1]);
    int ans = binSearchAnswer();
    if (ans < n) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}