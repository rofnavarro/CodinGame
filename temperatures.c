#include <stdlib.h>
#include <stdio.h>


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    // the number of temperatures to analyse
    int *numbers;
    int n;
    scanf("%d", &n);
    
    numbers = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        // a temperature expressed as an integer ranging from -273 to 5526
        scanf("%d", &numbers[i]);
    }
    int i = 0;
    int j;
    while (numbers[i])
    {
        j = i + 1;
        while (numbers[j])
        {
            if (numbers[i] < 0 && (-numbers[i]) == numbers[j])
                numbers[i] = numbers[j];
            j++;
        }
        i++;
    }
    i = 1;
    int tmp = numbers[0];
    while (numbers[i])
    {
        if (numbers[i] > 0)
        {
            if (numbers[i] < tmp)
                tmp = numbers[i];
        }
        else
        {
            if (numbers[i] == tmp * -1)
                i++;
            else if (numbers[i] >= tmp)
                tmp = numbers[i];
        }
        i++;
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", tmp);

    return 0;
}