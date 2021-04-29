#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum operator
{
    plus,
    minus,
    none
};

int calc(int a, enum operator op, int b)
{
    switch (op)
    {
    case plus:
        return a + b;
    case minus:
        return a - b;
    case none:
        return b;
    }
}

int main(void)
{
    char inputChar[80];
    gets(inputChar);
    int x;
    int result = 0;
    enum operator op = none;
    char tmp[80];
    for (int i = 0; i < strlen(inputChar); i++)
    {
        switch (inputChar[i])
        {
        case '+':
            op = plus;
            break;
        case '-':
            op = minus;
            break;
        case ' ':
            break;
        default:
            x = atoi(&inputChar[i]);
            result = calc(result, op, x);
            break;
        }
    }
    printf("%s = %d\n", inputChar, result);

    return 0;
}