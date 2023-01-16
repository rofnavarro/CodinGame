#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int * clear_dupes(int *array, int size)
{
    int i;
    int j;
    int dupes;
    int new_size;
    int *no_dupes;

    i = 0;
    dupes = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size - 1)
        {
            if (array[j] == array[i])
            {
                array[j] = -1;
                dupes++;
            }
            j++;
        }
        i++;
    }
    new_size = size - dupes;
    no_dupes = (int *)malloc(sizeof(int) * new_size);
    i = 0;
    j = 0;
    while (i < size)
    {
        if (array[i] > 0)
        {
            no_dupes[j] = array[i];
            j++;
        }
        i++;
    }
    free(array);
    return (no_dupes);
}

int main()
{
    int N;
    int *horses, *no_dupes;
    int j, k, tmp, answer;

    scanf("%d", &N);
    horses = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        int pi;
        scanf("%d", &pi);
        horses[i] = pi;
    }

    no_dupes = clear_dupes(horses, N);

    while (j < N)
    {
        k = j + 1;
        while (k < N)
        {
            tmp = abs(no_dupes[j] - no_dupes[k]);
            if (tmp < answer)
                answer = tmp;
            k++;
        }
        j++;
    }
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    printf("%d\n", answer);

    free(no_dupes);
    return 0;
}