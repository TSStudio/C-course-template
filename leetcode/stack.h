#pragma once
#ifndef __TSSTUDIO_STACK_H
#define __TSSTUDIO_STACK_H
#include <stdlib.h>

struct IntStack {
    int *data;
    int size;
    int maxSize;
    IntStack() {
        data = (int *)malloc(sizeof(int) * 100);
        maxSize = 100;
        size = 0;
    }
    int *push(int _element) {
        if (size * 2 > maxSize) {
            maxSize *= 2;
            data = (int *)realloc(data, sizeof(int) * maxSize);
        }
        data[size++] = _element;
        return &data[size - 1];
    }
    int pop() {
        if (size == 0) return NULL;
        return data[--size];
    }
    int top() {
        if (size == 0) return NULL;
        return data[size - 1];
    }
    bool empty() { return size == 0; }
    int getSize() { return size; }
    void clear() { size = 0; }
};
#endif  // __TSSTUDIO_STACK_H