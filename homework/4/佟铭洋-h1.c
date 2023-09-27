#include<stdio.h>
// Copyright Tong Mingyang 2023. All Rights Reserved.
// Module: homework/20230927/1
// This file is licensed under the MIT License.
// License text available at https://opensource.org/licenses/MIT

long long BinomialCoefficient(int n, int m) {
    long long ans=1;
    for(int i=1;i<=m;i++){
        ans=ans*(n-i+1)/i;
    }
    return ans;
}
int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%lld\n", BinomialCoefficient(n, m));
    getchar();getchar();
    return 0;
}