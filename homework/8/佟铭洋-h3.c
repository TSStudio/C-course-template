char findTheDifference(char* s, char* t) {
    char temp = 0;
    for (int i = 0; s[i]; ++i)
        temp ^= s[i];
    for (int i = 0; t[i]; ++i)
        temp ^= t[i];
    return temp;
}