#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

int main()
{
    int max_h;
    int index;

    // game loop
    while (1) 
    {
        max_h = 0;
        index = 0;

        for (int i = 0; i < 8; i++) 
        {
            // represents the height of one mountain.
            int mountain_h;
            scanf("%d", &mountain_h);
            if (mountain_h > max_h)
            {
                max_h = mountain_h;
                index = i;
            }
        }
        printf("%d\n", index); // The index of the mountain to fire on.
    }

    return 0;
}
