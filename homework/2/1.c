#include<stdio.h>

int main(void){
    int N;
    long long sum=0,tmp;
    scanf("%d", &N);
    for(int i=0;i<N;++i){
        scanf("%lld", &tmp);
        sum+=tmp;
    }
    printf("The sum is %lld\n", sum);
    #ifdef DEBUG
    getchar();getchar();
    #endif
    return 0;
}