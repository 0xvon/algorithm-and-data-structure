#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define lesseq(A, B) (A <= B)

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

void merge_sort(int a[], int l, int r) {
    int m = (l + r) / 2; // 真ん中
    // printf("l: %d, m: %d, r: %d\n", l, m, r);
    if (r <= l) return;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);

    _merge(a, l, m, r);
}

int main(void) {
    int n, i;
    scanf("%d", &n);

    int a[10000];
    for (i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        a[i] = t;
    }

    merge_sort(a, 0, n-1);
    
    for (i = 0; i < n; i++) printf("%d\n", a[i]);
    return 0;
}