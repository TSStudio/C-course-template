#include<stdio.h>

int main(void){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("The minimum is %d\n",a<(b<c?b:c)?a:(b<c?b:c));
    printf("The maximum is %d\n",a>(b>c?b:c)?a:(b>c?b:c));
    #ifdef DEBUG
    getchar();getchar();
    #endif
    return 0;
}