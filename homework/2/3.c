#include<stdio.h>
#include<stdlib.h>

int main(void){
    double min,tmp;
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;++i){
        scanf("%lf", &tmp);
        if(i==0) min=tmp;
        else if(tmp<min) min=tmp;
    }
    printf("The minimum is %.2lf\n", min);
    #ifdef DEBUG
    system("pause");
    #endif
    return 0;
}