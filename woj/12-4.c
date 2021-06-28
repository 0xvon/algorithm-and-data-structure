#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define lesseq(A, B) (A <= B)
#define min(A, B) (A < B) ? A : B

void _merge(int a[], int l, int m, int r) {
    int i, j, k;
    int aux[10000];

    for (i = m + 1; i > l; i--) aux[i - 1] = a[i - 1]; // そのまま代入
    for (j = m; j < r; j++) aux[r + m - j] = a[j + 1]; // 逆順にして代入
    for (k = l; k <= r; k++) {
        if (lesseq(aux[i], aux[j])) a[k] = aux[i++]; // iとjの要素を比較していく
        else a[k] = aux[j--];
    }
}

void merge_sort_bu(int a[], int l, int r) {
    int i, m;
    for (m = 1; m < r - 1; m = m + m) {
        for (i = l; i <= r - m; i += m + m) {
            _merge(a, i, i + m - 1, min(i + m + m - 1, r));
        }
    }
}

int main(void) {
    while(1) {
        int n, i;
        char array_type[10000];

        int ret = scanf("%d", &n);
        if (ret == EOF) break;
        scanf("%s", &array_type);

        int a[10000];
        for (i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            a[i] = t;
        }

        clock_t start, end;
        start = clock();
        merge_sort_bu(a, 0, n-1);
        end = clock();
        
        // for (i = 0; i < n; i++) printf("%d\n", a[i]);
        printf("%4fsec\n", (double)(end - start) / CLOCKS_PER_SEC);
    }
    
    return 0;
}