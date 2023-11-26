int strStr(char* haystack, char* needle) {
    int lengthHaystack = strlen(haystack), lengthNeedle = strlen(needle);
    for (int i = 0; i <= lengthHaystack - lengthNeedle; i++) {
        int j = i, k = 0;
        while (k < lengthNeedle && haystack[j] == needle[k]) {
            j++;
            k++;
        }
        if (k == lengthNeedle) return i;
    }
    return -1;
}