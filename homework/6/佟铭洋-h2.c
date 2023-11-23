char* convertToBase7(int num) {
    // 解决此题通常使用栈或者倒序字符串
    // 但此处我们稍微取巧一下
    // 直接将低位从res[18]往前存储
    // 最后再将指针指向最高位（第一个非0字符）
    if (num == 0) return "0";
    int numWithAbs = num > 0 ? num : -num;
    char* res = (char*)malloc(sizeof(char) * 20);
    int i = 19;
    while (numWithAbs) {
        res[--i] = numWithAbs % 7 + '0';
        numWithAbs /= 7;
    }
    if (num < 0) res[--i] = '-';
    res[19] = '\0';
    return res + i;
}