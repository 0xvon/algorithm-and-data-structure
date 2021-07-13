#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char alphabets[26] = "abcdefghijklnmopqrstuvwxyz";
    int i;
    int histgrams[26] = {0};
    int maxCount = 0;
    int frequentAlphabets[26];
    int frequentAlphabetCount = 0;

    while(1) {
        char alphabet;
        int ret = scanf("%c", &alphabet);
        if (ret == EOF) break;

        char loweredAlphabet = tolower((unsigned char) alphabet);
        for (i = 0; i < 26; i++) {
            if (alphabets[i] == loweredAlphabet) histgrams[i] ++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (histgrams[i] > maxCount) maxCount = histgrams[i];
    }
    printf("%d ", maxCount, frequentAlphabets);
    for (i = 0; i < 26; i++) {
        if (histgrams[i] == maxCount) printf("%c", alphabets[i]);
    }
    printf("\n");
    return 0;
}