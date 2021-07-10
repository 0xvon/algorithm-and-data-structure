#include <stdio.h>
#include <string.h>
#include <math.h>

double calcTaxIncludePrice(double taxRate, double price) {
    return price * (100 + taxRate) / 100;
}

double calcPrice(double taxRate, double taxIncludePrice) {
    return (taxIncludePrice * 100) / (100 + taxRate);
}

double calcMaxPrice(int taxRate, int taxIncludePrice) {
    double i, max = 0;
    for (i = 1; i < (taxIncludePrice); i++) {
        double price = (calcPrice(taxRate, i) + calcPrice(taxRate, (taxIncludePrice - i)));
        if (max < price) max = price;
    }
    return max;
}

int calcMaxAfterPrice(int beforeTaxRate, int afterTaxRate, int beforePrice) {
    double max = 0, i;
    double price;
    price = calcMaxPrice(beforeTaxRate, beforePrice); // 最大の税抜価格を計算
    for (i = 1; i <= (price); i++) {
        double newTaxIncludePrice;
        newTaxIncludePrice = calcTaxIncludePrice(afterTaxRate, i) + calcTaxIncludePrice(afterTaxRate, price - i);
        printf("x: %f, y: %f, p: %f\n", i, price - i, newTaxIncludePrice);
        if (max < newTaxIncludePrice) max = newTaxIncludePrice;
    }
    return max;
}

int main(void) {
    while(1) {
        int beforeTaxRate, afterTaxRate, beforePrice;
        int afterPrice;
        int ret = scanf("%d %d %d", &beforeTaxRate, &afterTaxRate, &beforePrice);
        if (ret == EOF) break;
        afterPrice = (int)calcMaxAfterPrice(beforeTaxRate, afterTaxRate, beforePrice);
        printf("%d\n", afterPrice);
    }
    return 0;
}
