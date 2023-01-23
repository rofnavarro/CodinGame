#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct  s_program
{
    char extension[11];
    char table[51];
}t_program;

char *search_table(char *file, t_program *table, int N)
{
    char    *ret;
    char    *tmp;
    int     size;
    int     ref;
    int     i;
    int     found;

    size = strlen(file);
    ref = size;
    while (file[ref] != '.' && ref != 0)
    {
        ref--;
    }

    tmp = (char *)malloc(sizeof(char) * (size - ref) + 1);
    tmp[(size - ref) + 1] = '\n';

    i = 0;
    while(file[++ref])
    {
        tmp[i] = tolower(file[ref]);
        i++;
    }
    i = 0;
    found = 1;
    while (found != 0)
    {
        while (i < N)
        {
            if (tmp[0] == table[i].extension[0])
            {
                if (strcmp(tmp, table[i].extension) == 0)
                {
                    //printf("%s\n", tmp);
                    //printf("%s\n", table[i].extension);
                    ret = table[i].table;
                    found = 0;
                }

            }
            i++;
        }
        if (found == 1)
        {
            ret = "UNKNOWN";
            found = 0;
        }
    }
    return (ret);
}

int main()
{
    t_program   *program;
    char        **files;
    int         i;

    // Number of elements which make up the association table.
    int N;

    scanf("%d", &N);
    program = (t_program *)malloc(sizeof(t_program) * N);

    // Number Q of file names to be analyzed.
    int Q;

    scanf("%d", &Q);
    files = (char **)malloc(sizeof(char *) * Q);
    i = 0;
    while  (i < Q)
    {
        files[i] = (char *)malloc(sizeof(char) * 257);
        i++;
    }


    for (i = 0; i < N; i++) 
    {
        // file extension
        char EXT[11];
        // MIME type.
        char MT[51];
        scanf("%s%s", EXT, MT); fgetc(stdin);
        for (int j = 0; j < strlen(EXT) + 1; j++)
        {
            EXT[j] = tolower(EXT[j]);
        }

        strcpy(program[i].extension, EXT);
        strcpy(program[i].table, MT);
    }

    for (int i = 0; i < Q; i++) 
    {
        // One file name per line.
        char FNAME[257];
        scanf("%[^\n]", FNAME); fgetc(stdin);
        strcpy(files[i], FNAME);
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    i = 0;
    while (i < Q)
    {
        char *ret;


        ret = search_table(files[i], program, N);
        printf("%s\n", ret);
        i++;

    }
    i = 0;
    while (i < Q)
    {
        free(files[i]);
        i++;
    }
    free(files);
    free(program);
    return 0;
}