#include<stdio.h>
// Copyright Tong Mingyang 2023. All Rights Reserved.
// Module: homework/20230920/3
// This file is licensed under the MIT License.
// License text available at https://opensource.org/licenses/MIT
void StringStatistics(char* str, int* numChars, int* numLines, int* numWords){
    int i = 0;
    *numChars = 0;
    *numLines = 0;
    *numWords = 0;
    while (*(str + i) != '\0') {
        if (*(str + i) == '\n') {
            (*numLines)++;
        }
        if (*(str + i) == ' ' || *(str + i) == '\n') {
            if(i==0) continue;//防越界
            if(*(str + i - 1) != ' ' && *(str + i - 1) != '\n'){
                (*numWords)++;
            }
        }
        //若计所有字符
        (*numChars)++;
        //若计非空字符
//         if (*(str + i) != ' ' && *(str + i) != '\n' && *(str + i) != '\t') {
//             (*numChars)++;
//         }
        i++;
    }
    if(i==0) return;//防越界
    if(*(str + i - 1) != ' ' && *(str + i - 1) != '\n'){
        (*numWords)++;
    }
    //若不计空行
//     if(*(str + i - 1) != '\n'){
//         (*numLines)++;
//     }
    //若计空行
    (*numLines)++;
}
int main(void){
    char str[1000]="I am a pig with two eyes. What about you?\nI am a cat with two ears. What about you?\nI am a dog with four legs. What about you?\n";
    int numChars;
    int numLines;
    int numWords;
    StringStatistics(str, &numChars, &numLines, &numWords);
    printf("%d %d %d\n", numChars, numLines, numWords);
    getchar();getchar();
    return 0;
    
}