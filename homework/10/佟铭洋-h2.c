int countGoodNumbers(long long n) {
    const long long mod = 1000000007;
    if (n == 1) {
        return 5;
    }
    if (n == 2) {
        return 20;
    }
    if (n % 2 == 1) {
        return (countGoodNumbers(n - 1) % mod * 5) % mod;
    } else {
        if (n % 4 == 0) {
            long long temp = countGoodNumbers(n / 2) % mod;
            return (temp * temp) % mod;
        } else {
            return (countGoodNumbers(n - 2) % mod * 20) % mod;
        }
    }
}