#include <stdio.h>
#include <math.h>

int main(void) {
    while(1) {
        int input;
        int expNum;
        int ret = scanf("%d", &input);
        if (ret == EOF) break;

        for (expNum = 1; expNum <= input; expNum += expNum + expNum) {
            if (expNum < 0) break;
            printf("%d\n", expNum);
        }
    }
    return 0;
}
