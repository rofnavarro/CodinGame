#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int find_start(char T, char *ROW, int L)
{
    int i = 0;
    char *alpha = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ?"};

    while (i < strlen(alpha))
    {
        if (toupper(T) == alpha[i])
            return (i * L); 
        i++;
    }
   return ((strlen(alpha) * L) - L);
}

int main()
{
    int L;
    scanf("%d", &L);
    int H;
    scanf("%d", &H); fgetc(stdin);
    char T[257];
    scanf("%[^\n]", T); fgetc(stdin);
    for (int i = 0; i < H; i++) {
        char ROW[1025];
        scanf("%[^\n]", ROW); fgetc(stdin);
    
        int start;
        int k = 0;
        while (T[k])
        {
            start = find_start(T[k], ROW, L);
            for (int j = start; j < (start + L); j++)
                printf("%c", ROW[j]);
            k++;
        }

        printf("\n");
    }

    return 0;
}