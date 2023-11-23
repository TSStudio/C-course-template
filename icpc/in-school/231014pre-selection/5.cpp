#include <cstdio>
#include <cmath>

int T, n, x_0, y_0;

typedef long double ld;
void calc(ld x_1, ld y_1, ld x_2, ld y_2, ld theta1, ld theta2, ld &x, ld &y) {
    ld a11 = sinl(theta1), a12 = -cosl(theta1), a21 = sinl(theta2), a22 = -cosl(theta2);
    ld b1 = x_1 * sinl(theta1) - y_1 * cosl(theta1), b2 = x_2 * sinl(theta2) - y_2 * cosl(theta2);
    x = (b1 * a22 - b2 * a12) / (a11 * a22 - a12 * a21);
    y = (b1 * a21 - b2 * a11) / (a12 * a21 - a11 * a22);
}

int main() {
#ifdef DEBUG
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &x_0, &y_0);
        if (n == 998244353) {
            return 0;
        }
        if (n <= 13) {
            printf("! impossible\n");
            fflush(stdout);
            continue;
        }
        long double theta1, theta2;
        printf("? %d %d\n", x_0, y_0 + 20);
        fflush(stdout);
        scanf("%Lf", &theta1);
        if (theta1 < -3.1416 || theta1 > 3.1416) {
            printf("! %d %d\n", x_0, y_0 + 20);
            fflush(stdout);
            continue;
        }
        if (theta1 > 1 && theta1 < 2 || theta1 > -2 && theta1 < -1) {
            printf("? %d %d\n", x_0 + 20, y_0);
            fflush(stdout);
            scanf("%Lf", &theta2);
            if (theta2 < -3.1416 || theta2 > 3.1416) {
                printf("! %d %d\n", x_0 + 20, y_0);
                fflush(stdout);
                continue;
            }
            ld x, y;
            calc(x_0, y_0 + 20, x_0 + 20, y_0, theta1, theta2, x, y);
            printf("! %d %d\n", (int)roundl(x), (int)roundl(y));

        } else {
            printf("? %d %d\n", x_0, y_0 - 20);
            fflush(stdout);
            scanf("%Lf", &theta2);
            if (theta2 < -3.1416 || theta2 > 3.1416) {
                printf("! %d %d\n", x_0, y_0 - 20);
                fflush(stdout);
                continue;
            }
            ld x, y;
            calc(x_0, y_0 + 20, x_0, y_0 - 20, theta1, theta2, x, y);
            printf("! %d %d\n", (int)roundl(x), (int)roundl(y));
        }
        fflush(stdout);
    }
    return 0;
}