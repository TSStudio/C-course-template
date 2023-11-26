char* multiply(char* num1, char* num2) {
    int length1 = strlen(num1), length2 = strlen(num2);
    int length = length1 + length2;
    int* result = (int*)malloc(sizeof(int) * length);
    memset(result, 0, sizeof(int) * length);
    for (int i = length1 - 1; i >= 0; i--) {
        for (int j = length2 - 1; j >= 0; j--) {
            result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for (int i = length - 1; i > 0; i--) {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }
    char* answer = (char*)malloc(sizeof(char) * (length + 1));
    int index = 0;
    while (index < length && result[index] == 0) index++;
    if (index == length) {
        answer[0] = '0';
        answer[1] = '\0';
        return answer;
    }
    for (int i = index; i < length; i++) {
        answer[i - index] = result[i] + '0';
    }
    answer[length - index] = '\0';
    return answer;
}