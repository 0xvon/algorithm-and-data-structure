#include <stdio.h>
#include <string.h>

char alphabets[26] = "abcdefghijklnmopqrstuvwxyz";
int calcCharIndex(char a) {
    int i;
    for (i = 0; i < 26; i ++) {
        if (alphabets[i] == a) return i;
    }
    return -1;
}

int main(void) {
    int youngestWordIndex[100] = {26};
    char youngestWord[100] = "xxxx";
    while(1) {
        char word[100];
        int i;
        int ret = scanf("%s", &word);
        if (ret == EOF) break;

        for (i = 0; i < strlen(word); i ++) {
            int index = calcCharIndex(word[i]);
            if (index == -1) break;
            if (youngestWordIndex[i] < index) break;
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