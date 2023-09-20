#include<stdio.h>
#include<string.h>
#include<time.h>

int a[1000][1000], b[1000][1000], c[1000][1000],d[1000][1000];
const int N=1000;
int time1,time2;//in ms
time_t start,end;
void matrix_mul_method_1(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                c[i][j]+=a[i][k]*b[k][j];
}
void pre_T(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            d[i][j]=b[j][i];
}
void matrix_mul_method_2(){
    pre_T(b,d,N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                c[i][j]+=a[i][k]*d[j][k];
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //input a
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&a[i][j]);
    //input b
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&b[i][j]);
    //method 1
    memset(c,0,sizeof(c));
    start=clock();
    matrix_mul_method_1();
    end=clock();
    time1=(end-start)*1000/CLOCKS_PER_SEC;
    printf("METHOD 1:\n");
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            printf("%d%c",c[i][j],j==N-1?'\n':' ');
    //method 2
    memset(c,0,sizeof(c));
    start=clock();
    matrix_mul_method_2();
    end=clock();
    time2=(end-start)*1000/CLOCKS_PER_SEC;
    printf("METHOD 2:\n");
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            printf("%d%c",c[i][j],j==N-1?'\n':' ');
    printf("METHOD 1: %dms\nMETHOD 2: %dms\n",time1,time2);
    return 0;
}