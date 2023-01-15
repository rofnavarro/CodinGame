#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int count_uniq(int *horses)
{
    int i;
    int j;
    int size;

    i = 0;
    size = 0;
    while (horses[i])
    {
        while (horses[j])
        {
            if (horses[j] != horses[i])
                size++;
            j++;
        }
        i++;
    }
    return (size);
}

int *zero_array(int *uniques, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        uniques[i] = 0;
        i++;
    }
    return (uniques);
}

int *unique_array(int *uniques, int *horses, int size)
{
    int i;
    int j;
    int control;

    i = 0;
    uniques[0] = horses[0];
    control = 1;
    while (horses[i])
    {
        j = 0;
        while (j <= control)
        {
            compare(horses[i], uniques)
            j++;
        }
        i++;
    }

    return (uniques);
}

int main()
{
    int N;
    int *horses;
    int size;
    int *uniques;
    int answer;

    answer = -1;
    scanf("%d", &N);

    horses = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        int pi;
        scanf("%d", &pi);
        horses[i] = pi;
    }
    size = count_uniq(horses);
    uniques = (int *)malloc(sizeof(int) * size);
    uniques = zero_array(uniques, size);
    uniques = unique_array(uniques, horses, size);
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", answer);

    return 0;
}