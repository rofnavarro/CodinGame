#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

char *coding(char *str)
{
    int i, j;

    i = 0;
    while (i < 7)
    {
        if (str[i] == '1')
        {
            j = i;
            while (str[j] == '1')
        }
    }

}


char *char_to_bit(char letter)
{
    int i, j;
    int bit;
    char *ret;

    ret = (char *)malloc(sizeof(char) * 7);
    i = 0;
    j = 6;
    while (i < 7)
    {
        bit = ((letter >> i) & 1);
        if (bit == 1)
            ret[j] = '1';
        else if (bit == 0)
            ret[j] = '0';
        j--;
        i++;
    }
    ret[7] = '\0';
    printf("%s\n", ret);
    return (ret);
}

int main()
{
    char MESSAGE[101];
    char **ret;
    int i;
    unsigned int size;

    scanf("%[^\n]", MESSAGE);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    size = strlen(MESSAGE) + 1;
    ret = (char **)malloc(sizeof(char) * size);
    i = 0;
    while (i < size - 1)
    {
        ret[i] = char_to_bit(MESSAGE[i]);
        i++;
    }
    i = 0;
    while (i < size)
    {
        free(ret[i]);
        i++;
    }
    free(ret);
    return 0;
}