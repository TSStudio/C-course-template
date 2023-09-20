#include<stdio.h>
#include<stdlib.h>

int main(){
    srand(5555U);
    freopen("input.txt","w",stdout);
    int N=1000;
    //generate N*N*2 random numbers
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            printf("%d%c",rand()%100,j==N-1?'\n':' ');
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            printf("%d%c",rand()%100,j==N-1?'\n':' ');
    return 0;
}