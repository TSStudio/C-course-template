#include<stdio.h>
#include<stdbool.h>
int n;
bool isPrime(int a) {
    if(a<2) return false;
    for(int i=2;i*i<=a;++i) if(a%i==0) return 0;
    return true;
}
int main(void){
    scanf("%d",&n);
    printf("%d is ",n);
    if(isPrime(n)) printf("a prime\n");
    else printf("not a prime\n");
    #ifdef DEBUG
    getchar();getchar();
    #endif
    return 0;
}