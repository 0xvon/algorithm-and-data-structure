#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    while(1) {
        int n;
        int ret = scanf("%d", &n);
        if (ret == EOF || n == 0) break;

        int count = 0, i, j;

        // エラトステネスの篩を2nまで行なう
        int arr[1000000] = {0};
        for(i = 2; i <= n * 2; i++) arr[i] = 1;

        for (i = 2; i <= (int)sqrt(n * 2); i++) {
            if (arr[i] == 1) {
                for (j = 2 * i; j <= n * 2; j = i + j) arr[j] = 0;
            }
        }
        // nから2nまでの素数の個数を数え上げ
        for ( i = n + 1; i <= n * 2; i++) {
            if (arr[i] == 1) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
