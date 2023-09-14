#include<stdio.h>

int main(void){
    int n,output=0;
    scanf("%d",&n);
    //我会for！！！但for不是时间复杂度最低的做法
    //for(int i=1;i<=n;++i) output+=i;
    printf("%d",(1+n)*n/2);
    #ifdef DEBUG
    getchar();getchar();
    #endif
    return 0;
}