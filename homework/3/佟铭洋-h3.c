#include<stdio.h>
#include<stdbool.h>
// Copyright Tong Mingyang 2023. All Rights Reserved.
// Module: homework/20230920/3
// This file is licensed under the MIT License.
// License text available at https://opensource.org/licenses/MIT

const char* delimiters = " \n\t.,;:!?()[]{}'\"";
bool isEmpty(char c){
    int i = 0;
    while (*(delimiters + i) != '\0') {
        if(*(delimiters + i) == c) return true;
        i++;
    }
    return false;
}
void StringStatistics(char* str, int* numChars, int* numLines, int* numWords){
    int i = 0;
    *numChars = 0;
    *numLines = 0;
    *numWords = 0;
    while (*(str + i) != '\0') {
        if(*(str + i) == '\n') (*numLines)++;
        if(!isEmpty(*(str + i))){
            if(i==0) (*numWords)++;
            else if(isEmpty(*(str + i - 1))) (*numWords)++;
        }
        (*numChars)++;
        i++;
    }
    if(i==0) return;//防越界
    //若不计空行
//     if(*(str + i - 1) != '\n'){
//         (*numLines)++;
//     }
    //若计空行
    (*numLines)++;
}
int main(void){
    char str[1000]="it's a \n good day.\n";
    //有几个问题
    //第一个是 测试样例：it's a \n good day.\n 中的 ' 是全角符号则会被记为3个字符（UTF-8），而且在不同字符编码下不一致，请问测试样例的数据保证均为ASCII字符吗？
    //第二个是 单词统计应该是统计连续的非空字符串数量？例如上述的测试样例，我们会认为it's是一个单词，而不是两个单词it和s，但老师给出的numWords为5，这是将'认为成了空格，而不是单词的一部分，还是其他原因？
    //第三个是 是否保证标点是合法输入的 例如是否会出现 I am a student , but I am not a good student. 这样的输入？如果是这样我或许还要换一种parse的思路。
    int numChars;
    int numLines;
    int numWords;
    StringStatistics(str, &numChars, &numLines, &numWords);
    printf("%d %d %d\n", numChars, numLines, numWords);
    getchar();getchar();
    return 0;
    
}