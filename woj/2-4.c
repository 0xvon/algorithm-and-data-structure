#include <stdio.h>
#include <math.h>

int main(void) {
    int num[80];
    int input, i, j;
    int order[81] = {9};
    int moveUp[81] = {0};
    int ret = scanf("%d", &input);
    if (ret == EOF) exit(1);
    if (input >= 80) exit(1);

    while(order[input] == 0 && order[input + 1] == 0) {
        for (i = 0; i <= input; i++) {
            num[i] = order[i];
            order[i] *= 3;
            order[i] += moveUp[i]; // move up
            moveUp[i] = 0; // and then reset
            if (order[i] > 9) {
                moveUp[i + 1] += order[i] / 10; // push new move up wen needed
                order[i] %= 10;
            }
            // printf("%d: num[i]: %d, order[i]: %d, flag[i+1]: %d\n", i, num[i],  order[i], moveUp[i+1]);
        }
    }
    for (i = input - 1; i >= 0; i--) {
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;
}
