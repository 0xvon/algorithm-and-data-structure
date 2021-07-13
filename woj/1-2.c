#include <stdio.h>
#include <math.h>

int main(void) {
    while(1) {
        int input;
        int expNum; // 3のべき乗数
        int ret = scanf("%d", &input);
        if (ret == EOF) break;

        // expNumを1に設定し、3の倍数に更新していく
        for (expNum = 1; expNum <= input; expNum += expNum + expNum) {
            if (expNum < 0) break; // 数字がオーバーフローしたら終了
            printf("%d\n", expNum);
        }
    }
    return 0;
}
