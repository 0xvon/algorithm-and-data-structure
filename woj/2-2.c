#include <stdio.h>
#include <string.h>

typedef enum {
    CODE, SLASH, COMMENT, STAR,
} CodeState;

int main(void) {
    int commentCount = 0;
    CodeState state = CODE;
    while(1) {
        char code;
        int ret = scanf("%c", &code);
        if (ret == EOF) break;

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
                commentCount ++;
            } else if (code != '*') state = COMMENT;
            break;
        }
    }
    printf("%d", commentCount);
    printf("\n");
    return 0;
}