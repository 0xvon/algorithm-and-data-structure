#include <stdio.h>
#include <string.h>

int main(void) {
    char firstName[1000] = "taro", secondName[1000];
    int firstScore = 100000;
    int secondScore = 10000;

    while(1) {
        char name[100];
        int score;
        int ret = scanf("%s %d", &name, &score);
        if (ret == EOF) break;

        if (score < firstScore) {
            strcpy(secondName, firstName);
            strcpy(firstName, name);
            secondScore = firstScore;
            firstScore = score;
        }
        else if (score < secondScore) {
            strcpy(secondName, name);
            secondScore = score;
        }
    }
    printf("%s\n%s", firstName, secondName);
    printf("\n");
    return 0;
}
