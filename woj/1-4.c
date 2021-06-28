#include <stdio.h>
#include <math.h>

double calcSTriangle(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int validateTriangle(double a, double b, double c) {
    return a + b > c && a + c > b && b + c > a;
}

int main(void) {
    int minIndex = 0;
    int minS = 1000;

    int index = 1;
    while(1) {
        double a, b, c;
        double s;
        int ret = scanf("%lf %lf %lf", &a, &b, &c);
        if (ret == EOF) break;
        int isValidate = validateTriangle(a, b, c);
        if (isValidate) {
            s = calcSTriangle(a, b, c);
            // printf("index: %d, s: %lf, validate: %d\n", index, s, isValidate);
            if (s < minS) {
                minS = s;
                minIndex = index;
            }
        }
        index++;
    }
    printf("%d\n", minIndex);
    return 0;
}