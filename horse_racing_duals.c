#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
    int *horse;

    scanf("%d", &N);

    horse = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        int pi;
        scanf("%d", &pi);
        horse[i] = pi;
    }

    int i = 1;
    int j;
    int answer = -1;
    int tmp;
    while (i < N)
    {
        j = i + 1;
        while (j < N)
        {
            tmp = abs(i - j);
            if (tmp < abs(answer))
                answer = tmp;
            j++;
        }
        i++;
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", abs(answer));

    return 0;
}