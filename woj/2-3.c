#include <stdio.h>
#include <string.h>

char alphabets[26] = "abcdefghijklnmopqrstuvwxyz";

// アルファベットの若さ(aならば0, zならば25)を返す関数
int calcCharIndex(char a) {
    int i;
    for (i = 0; i < 26; i ++) {
        if (alphabets[i] == a) return i;
    }
    return -1;
}

int main(void) {
    int youngestWordIndex[100] = {26}; // 一番若い単語のアルファベットごとの若さ
    char youngestWord[100] = "xxxx"; // 一番若い単語
    while(1) {
        char word[100];
        int i;
        int ret = scanf("%s", &word);
        if (ret == EOF) break;

        for (i = 0; i < strlen(word); i ++) {
            int index = calcCharIndex(word[i]);
            if (index == -1) break;
            if (youngestWordIndex[i] < index) break;

            // アルファベットごとを比較し、新しく入力された単語のほうが若ければ解を更新
            // 若くなければその時点でbreakし、アルファベットが終了したらアルファベット数が少ないほうが若いとみなして解を更新
            if (youngestWordIndex[i] > index || i == (strlen(word) - 1)) {
                youngestWordIndex[i] = index;
                strcpy(youngestWord, word);
            }
            
        }
    }
    printf("%s", youngestWord);
    printf("\n");
    return 0;
}