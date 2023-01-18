#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


char *join(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result)
    {
        strcpy(result, s1);
        strcat(result, s2);
    }
    return result;
}

char *binary_to_unary(char *binary)
{
    char *unary;
    unsigned int size = strlen(binary) + 1;
    int i, j;

    unary = (char *)malloc(sizeof(char));
    i = 0;
    while (i < size - 1)
    {   
        j = i + 1;
        if (binary[i] == '1')
        {
            unary = join(unary, "0 0");
            while  (binary[j] == '1' && binary[j] != '\0')
            {
                unary = join(unary, "0");
                j++;
            }
            if (j < size)
               unary = join(unary, " ");
        }
        else if(binary[i] == '0')
        {
            unary = join(unary, "00 0");
            while (binary[j] == '0' && binary[j] != '\0')
            {
                unary = join(unary, "0");
                j++;
            }
            if (j < size)
                unary = join(unary, " ");
        }
        i = j - 1;
        i++;
    }
    size = strlen(unary) - 1;
    unary[size] = '\0';
    return (unary);
}


char *char_to_bit(char letter)
{
    int i, j;
    int bit;
    char *ret;

    ret = (char *)malloc(sizeof(char) * 8);
    i = -1;
    j = 7;
    while (++i < 7)
    {
        j--;
        bit = ((letter >> i) & 1);
        if (bit == 1)
            ret[j] = '1';
        else if (bit == 0)
            ret[j] = '0';
    }
    ret[7] = '\0';
    return (ret);
}

int main()
{
    char MESSAGE[101];
    char **ret;
    int i;
    unsigned int size;
    char *binary;

    scanf("%[^\n]", MESSAGE);

    size = strlen(MESSAGE) + 1;
    ret = (char **)malloc(sizeof(char) * size);
    binary = (char *)malloc(sizeof(char));
    
    i = 0;
    while (i < strlen(MESSAGE))
    {
        ret[i] = char_to_bit(MESSAGE[i]);
        binary = join(binary, ret[i]);
        i++;
    }

    binary = binary_to_unary(binary);
    printf("%s\n", binary);
    free(ret);
    free(binary);

    return 0;
}