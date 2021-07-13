#include <stdio.h>
#include <string.h>

// BMIを計算する関数
double calcBmi(double height, double weight) {
    return weight / (height * height) * 10000;
}

int main(void) {
    char lowestBmiMan[100]; // 一番BMIが低い人の名前
    int lowestBmi = 1000; // 一番低いBMI値
    while(1) {
        char name[100];
        double height, weight;
        int ret = scanf("%s %lf %lf", &name, &height, &weight);
        if (ret == EOF) break;

        double bmi = calcBmi(height, weight);

        // BMIが一番低かったら解を更新
        if (lowestBmi > bmi) {
            lowestBmi = bmi;
            strcpy(lowestBmiMan, name);
        }
    }
    printf("%s\n", lowestBmiMan);
    return 0;
}