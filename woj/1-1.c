#include <stdio.h>

int main(void) {
    int nums[10000];
    int i = 0;
    int continuousEqualCount = 1;
    int maxContinuousEqualCount = 0;
    int maxContinuousEqualNumber = 0;

    while(1) {
        int ret = scanf("%d", &nums[i]);
        if (ret == EOF) break;

        if (i != 0) {
            if (nums[i - 1] == nums[i]) {
                continuousEqualCount ++;
            } else {
                if (continuousEqualCount >= maxContinuousEqualCount) {
                    maxContinuousEqualCount = continuousEqualCount;
                    maxContinuousEqualNumber = nums[i - 1];
                }
                continuousEqualCount = 1;
            }
        }
        i++;
    }
    if (continuousEqualCount >= maxContinuousEqualCount) {
        maxContinuousEqualCount = continuousEqualCount;
        maxContinuousEqualNumber = nums[i - 1];
    }
    
    printf("%d %d\n", maxContinuousEqualCount, maxContinuousEqualNumber);
    return 0;
}
