#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    while(1) {
        char word[10000], input[10000], first[1000];
        char *separated;
        int i;
        if (fgets(word, 10000, stdin) == NULL) break; // 標準入力をwordに代入
        if (strcmp(word, "\n") == 0) fprintf(stderr, "\n"); // 改行文字のみのチェック
        word[strlen(word) - 1] = '\0';
        strcpy(input, word);

        separated = strtok(word, " "); // 空白文字でsplit
        if (separated == NULL) continue; // 空白文字のみチェック
        strcpy(first, separated);
        separated = strtok(NULL, " "); // 2つめがあるかどうかのチェック
        if (separated != NULL) fprintf(stderr, "%s\n", input);
        else printf("%s\n", first);
    }
    return 0;
}