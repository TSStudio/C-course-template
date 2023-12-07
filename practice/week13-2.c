#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <times>\n", argv[0]);
        return 1;
    }
    int times = (int)strtol(argv[1], NULL, 10);
    for (int i = 0; i < times; i++) {
        printf("Hello, world!\n");
    }
    return 0;
}