#include<stdio.h>
#include<math.h>
// Copyright Tong Mingyang 2023. All Rights Reserved.
// Module: homework/20230920/1
// This file is licensed under the MIT License.
// License text available at https://opensource.org/licenses/MIT
void SolveQuadraticEquation(float a, float b, float c, int* numSolutions, float* solution) {
    float delta = b * b - 4 * a * c;
    if (delta < 0) {
        *numSolutions = 0;
    } else if (delta == 0) {
        *numSolutions = 1;
        *solution = -b / (2 * a);
    } else {
        *numSolutions = 2;
        *solution = (-b + sqrt(delta)) / (2 * a);
        *(solution + 1) = (-b - sqrt(delta)) / (2 * a);
    }
}
int main(void){
    float a, b, c;
    int numSolutions;
    float solution[2];
    scanf("%f%f%f", &a, &b, &c);
    SolveQuadraticEquation(a, b, c, &numSolutions, solution);
    if (numSolutions == 0) {
        printf("No solution\n");
    } else if (numSolutions == 1) {
        printf("One solution: %f\n", solution[0]);
    } else {
        printf("Two solutions: %f, %f\n", solution[0], solution[1]);
    }
    getchar();getchar();
    return 0;
}