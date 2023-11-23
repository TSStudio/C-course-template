#include<stdio.h>
#include<math.h>
// Copyright Tong Mingyang 2023. All Rights Reserved.
// Module: homework/20230927/3
// This file is licensed under the MIT License.
// License text available at https://opensource.org/licenses/MIT

double f(double x) {
    return exp(x*x);
}
double simpson(double l, double r) {
    double mid=(l+r)/2;
    return (r-l)*(f(l)+4*f(mid)+f(r))/6;
}
double Integral_simpson(double a, double b, double err) {
    double h=b-a;
    double fa=f(a), fb=f(b), fc=f((a+b)/2);
    double S=simpson(a, b), T=simpson(a, (a+b)/2)+simpson((a+b)/2, b);
    if(fabs(S-T)<15*err){
        return T;
    }
    return Integral_simpson(a, (a+b)/2, err/2)+Integral_simpson((a+b)/2, b, err/2);
}
double Integral_simple(double a, double b, double err) {//太慢了
    double h=fabs(b-a);
    double fa=f(a), fb=f(b);
    if(fabs(fa-fb)*h<err){
        return (fa+fb)*h/2;
    }
    return Integral_simple(a,(a+b)/2,err/2)+Integral_simple((a+b)/2,b,err/2);
}
double Integral(double a, double b, double err) {
    return Integral_simpson(a, b, err);
}
int main(void){
    double a, b, err;
    scanf("%lf%lf%lf", &a, &b, &err);
    printf("%.5lf\n", Integral_simpson(a, b, err));
    printf("%.5lf\n", Integral(a, b, err));
    
    getchar();getchar();
    return 0;
}