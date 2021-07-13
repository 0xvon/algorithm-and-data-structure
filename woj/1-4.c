#include <stdio.h>
#include <math.h>

// ヘロンの公式によって三角形の面積を求める
double calcSTriangle(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// 三角形が判定するかどうか判定
int validateTriangle(double a, double b, double c) {
    return a + b > c && a + c > b && b + c > a;
}

int main(void) {
    int minIndex = 0; // 最小面積を持つ三角形のインデックス
    int minS = 1000; // 最小面積

    int index = 1;
    while(1) {
        double a, b, c; // それぞれの辺の長さ
        double s;
        int ret = scanf("%lf %lf %lf", &a, &b, &c);
        if (ret == EOF) break;

        
        int isValidate = validateTriangle(a, b, c);

        // 三角形が存在するかどうか
        if (isValidate) {
            // 存在するなら面積を求め、最小面積なら解を更新
            s = calcSTriangle(a, b, c);
            if (s < minS) {
                minS = s;
                minIndex = index;
            }
        }
        index++;
    }
    printf("%d\n", minIndex);
    return 0;
}