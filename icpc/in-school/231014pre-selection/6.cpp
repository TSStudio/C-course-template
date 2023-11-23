#include <cstdio>
#include <cstring>

struct plan {
    int k, m;
} vis[200005];
int a[200005], tops[200005], topCount = 0, maxh;
int n, k_0;

void updateDFS(int u, int r) {
    //printf("r: %d, expanding from %d\n", r, u);
    for (int i = 1;; ++i) {
        if (a[u + i] == -1 || u + i > n || a[u + i] >= a[u]) {
            //printf("r: %d, from %d expanding to %d failed.\n", r, u, u + i);
            break;
        }
        if (i > r) {
            //printf("r: %d, from %d expanding to %d failed, but continue at%d\n", r, u, u + i, u + i - 1);
            updateDFS(u + i - 1, r);
            break;
        }
        if (vis[u + i].k > vis[u].k + 1 && (vis[u + i].m == 0x3f3f3f3f || a[u] > a[vis[u + i].m] || a[u] == a[vis[u + i].m] && u < vis[u + i].m)) {
            vis[u + i].k = vis[u].k + 1;
            vis[u + i].m = u;
        }
    }
    for (int i = -1;; --i) {
        if (a[u + i] == -1 || u + i < 1 || a[u + i] >= a[u]) {
            //printf("r: %d, from %d expanding to %d failed.\n", r, u, u + i);
            break;
        }
        if (i < -r) {
            //printf("r: %d, from %d expanding to %d failed, but continue at%d\n", r, u, u + i, u + i + 1);
            updateDFS(u + i + 1, r);
            break;
        }
        if (vis[u + i].k > vis[u].k + 1 && (vis[u + i].m == 0x3f3f3f3f || a[u] > a[vis[u + i].m] || a[u] == a[vis[u + i].m] && u < vis[u + i].m)) {
            vis[u + i].k = vis[u].k + 1;
            vis[u + i].m = u;
        }
    }
}

bool isOk(int answer_r) {
    memset(vis, 0x3f, sizeof(vis));
    for (int i = 0; i < topCount; ++i) {
        vis[tops[i]].k = 0;
    }
    for (int i = 0; i < topCount; ++i) {
        updateDFS(tops[i], answer_r);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i].k > k_0 && a[i] != -1) {
            //printf("r: %d, %d failed at %d > %d.\n", answer_r, i, vis[i].k, k_0);
            return false;
        }
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
        if (a[i] == maxh) tops[topCount++] = i;
    }
    int ans = binSearchAnswer();
    if (ans < n) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}