#include <stdio.h>
#include <string.h>

double calcBmi(double height, double weight) {
    return weight / (height * height) * 10000;
}

int main(void) {
    char lowestBmiMan[100];
    int lowestBmi = 1000;
    while(1) {
        char name[100];
        double height, weight;
        int ret = scanf("%s %lf %lf", &name, &height, &weight);
        if (ret == EOF) break;

        double bmi = calcBmi(height, weight);
        // printf("name: %s, height: %lf, weight: %lf, bmi: %lf\n", name, height, weight, bmi);
        if (lowestBmi > bmi) {
            lowestBmi = bmi;
            strcpy(lowestBmiMan, name);
        }
    }
    printf("%s\n", lowestBmiMan);
    return 0;
}