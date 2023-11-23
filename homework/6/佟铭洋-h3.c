char* decodeMessage(char* key, char* message) {
    char converter[26] = {};
    int j = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] == ' ') continue;
        if (converter[key[i] - 'a']) {
            continue;
        }
        converter[key[i] - 'a'] = (j++) + 'a';
    }
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] != ' ') {
            message[i] = converter[message[i] - 'a'];
        }
    }
    return message;
}