#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char alphabets[26] = "abcdefghijklnmopqrstuvwxyz"; // アルファベットの集合
    int i;
    int histgrams[26] = {0}; // アルファベットの出現回数

    while(1) {
        char alphabet;
        int ret = scanf("%c", &alphabet); // 一文字ずつscanする
        if (ret == EOF) break;

        char loweredAlphabet = tolower((unsigned char) alphabet); // 小文字に変換
        for (i = 0; i < 26; i++) {
            if (alphabets[i] == loweredAlphabet) histgrams[i] = 1; // アルファベットが存在するなら出現回数を1に
        }
    }
    for (i = 0; i < 26; i++) {
        if (histgrams[i] == 0) printf("%c", alphabets[i]); // 出現回数が0ならprintする
    }
    printf("\n");
    return 0;
}