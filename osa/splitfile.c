#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int ifd, fofd, sofd, input, firstOutputFile, secondOutputFile;
    int i, l, r, splitPoint;
    char inputText[10000];
    char leftText[10000] = "";
    char rightText[10000] = "";
    
    ifd = open(argv[1], O_RDONLY);
    if (ifd == -1) perror("error when opening input file");
    input = read(ifd, inputText, 10000);
    if (input == -1) perror("error when reading input file");
    inputText[input] = '\0';

    fofd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    sofd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    
    splitPoint = atoi(argv[4]);
    for (i = 0; i < strlen(inputText); i++) {
        if (i < splitPoint) leftText[l++] = inputText[i];
        else rightText[r++] = inputText[i];
    }
    write(fofd, leftText, strlen(leftText));
    write(sofd, rightText, strlen(rightText));
    close(ifd);
    close(fofd);
    close(sofd);
    return 0;
}
