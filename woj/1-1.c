#include <stdio.h>

int main(void) {
    int nums[10000];
    int i = 0;
    int continuousEqualCount = 1; // 連続して現れた回数の暫定値
    int maxContinuousEqualCount = 0; // 連続して現れた回数
    int maxContinuousEqualNumber = 0; // 連続して現れた数

    while(1) {
        int ret = scanf("%d", &nums[i]);
        if (ret == EOF) break;

        if (i != 0) {
            // nums[i]が前と連続しているかどうか
            if (nums[i - 1] == nums[i]) {
                continuousEqualCount ++;
            } else {
                // 解を更新するかどうか
                if (continuousEqualCount >= maxContinuousEqualCount) {
                    maxContinuousEqualCount = continuousEqualCount;
                    maxContinuousEqualNumber = nums[i - 1];
                }
                continuousEqualCount = 1;
            }
        }
        i++;
    }
    
    // 解を更新するかどうか
    if (continuousEqualCount >= maxContinuousEqualCount) {
        maxContinuousEqualCount = continuousEqualCount;
        maxContinuousEqualNumber = nums[i - 1];
    }
    
    printf("%d %d\n", maxContinuousEqualCount, maxContinuousEqualNumber);
    return 0;
}
