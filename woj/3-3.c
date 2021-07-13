#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    while(1) {
        long long n, x;
        long long c_n = 0;
        double pie;
        int ret = scanf("%lld", &n);
        if (ret == EOF) break;

        for (x = 1; x < n; x++) { // 軸以外の整数格子点の数を数える
            long long t = n * n - x * x; 
            if (t >= 0) {
                c_n += (long long)sqrt(t);
            }
        }
        c_n = 4 * c_n + 4 * n + 1; // 軸上の整数格子点の数を数える
        pie = ((double)(c_n) / (double)(n * n)); // πを計算
        printf("%d:%.15f\n", (int)n, pie);
    }
    return 0;
}
