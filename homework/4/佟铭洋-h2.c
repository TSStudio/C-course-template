#include<stdio.h>
// Copyright Tong Mingyang 2023. All Rights Reserved.
// Module: homework/20230927/2
// This file is licensed under the MIT License.
// License text available at https://opensource.org/licenses/MIT

void ToLowerCase(char* str) {
    for(int i=0;str[i]!='\0';++i){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]=str[i]-'A'+'a';
        }
    }
    return;
}
int main(void){
    char a[]="Hello World!\nHello China!\nHello Beijing!\n";
    ToLowerCase(a);
    printf("%s", a);
    getchar();getchar();
    return 0;
}