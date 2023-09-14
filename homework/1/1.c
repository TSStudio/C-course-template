#include<stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    //In C99+, use compiler param: -std=C99
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            printf("*");
        }
        printf("\n");
    }
    #ifdef DEBUG
    // prevent exit when debugging
    getchar();getchar();
    #endif
    return 0;
}