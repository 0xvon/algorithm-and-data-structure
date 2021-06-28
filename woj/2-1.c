#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char alphabets[26] = "abcdefghijklnmopqrstuvwxyz";
    int i;
    int histgrams[26] = {0};

    while(1) {
        char alphabet;
        int ret = scanf("%c", &alphabet);
        if (ret == EOF) break;

        char loweredAlphabet = tolower((unsigned char) alphabet);
        // printf("alp: %c, lowered: %c\n", alphabet, loweredAlphabet);
        // printf("%d\n", 'a' == loweredAlphabet);
        for (i = 0; i < 26; i++) {
            if (alphabets[i] == loweredAlphabet) histgrams[i] = 1;
        }
    }
    for (i = 0; i < 26; i++) {
        if (histgrams[i] == 0) printf("%c", alphabets[i]);
    }
    printf("\n");
    return 0;
}