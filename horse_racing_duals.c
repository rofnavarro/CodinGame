#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int * no_dupes(int *array, int size)
{
    int new_size, i, j;
    int *ret;

    i = 0;
    new_size = size;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (array[j] == array[i])
            {
                array[j] = -1;
                new_size--;
            }
            j++;
        }
        i++;
    }
    ret = (int *)malloc(sizeof(int) * new_size);
    i = 0;
    j = 0;
    while (i < new_size)
    {
        if (array[i] != -1)
        {
            ret[j] = array[i];
            j++;
        }
        i++;
    }
    free(array);
    return (ret);
}

int sort(int *array, int size)
{
    int i, tmp;

    for(int contador = 1; i < size; contador++)
    {
        for (i = 0; i < size - 1; i++)
        {
            if(array[i] < array[i+1])
            {
                tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
            }
        }
    }
    size++;
    return (size);
}

int main()
{
    int N;
    int answer;
    int *horses;

    scanf("%d", &N);

    horses = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        int pi;
        scanf("%d", &pi);
        horses[i] = pi;
    }

    horses = no_dupes(horses, N);
    N = sort(horses, N);

    int tmp, i, j;

    i = 0;
    while (i < N)
    {
        j = i + 1;
        while (j < N - 1)
        {
            tmp = abs(horses[i]) - abs(horses[j]);
            if (tmp < answer)
                answer = abs(tmp);
            j++;
        }
        i++;
    }
    printf("%d\n", answer);
    return 0;
}