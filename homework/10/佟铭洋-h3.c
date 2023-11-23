double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (n == -1) return 1.0 / x;
    if (n == 1) return x;
    if (x == 0) return 0;
    double half = myPow(x, n / 2);
    double rest = myPow(x, n % 2);
    return half * half * rest;
}