#include <stdio.h>
#include <string.h>

// コードの状態を定義する
typedef enum {
    CODE, // コード中
    SLASH, // コメント始まりの/入力中
    COMMENT, // コメント中
    STAR, // コメント終わりの*入力中
} CodeState;

int main(void) {
    int commentCount = 0; // コメントの数
    CodeState state = CODE;
    while(1) {
        char code;
        int ret = scanf("%c", &code); // 一文字ずつコードを読み込む
        if (ret == EOF) break;

        // 状態を更新
        switch (state) {
        case CODE:
            if (code == '/') state = SLASH;
            break;
        case SLASH:
            if (code == '*') state = COMMENT;
            else if (code != '/') state = CODE;
            break;
        case COMMENT:
            if (code == '*') state = STAR;
            break;
        case STAR:
            if (code == '/') {
                state = CODE;
                commentCount ++; // コメント終了なのでコメント数を+1する
            } else if (code != '*') state = COMMENT;
            break;
        }
    }
    printf("%d", commentCount);
    printf("\n");
    return 0;
}