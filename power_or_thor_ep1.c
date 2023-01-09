#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    // the X position of the light of power
    int light_x;
    // the Y position of the light of power
    int light_y;
    // Thor's starting X position
    int initial_tx;
    // Thor's starting Y position
    int initial_ty;
    scanf("%d%d%d%d", &light_x, &light_y, &initial_tx, &initial_ty);

    int diff_x;
    int diff_y;

    char *direction[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};

    int index;

    diff_x = +light_x - initial_tx;
    diff_y = -light_y + initial_ty; 
    index = 0;
    // game loop
    while (1) {
        // The remaining amount of turns Thor can move. Do not remove this line.
        int remaining_turns;
        scanf("%d", &remaining_turns);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        if (diff_x == 0 || diff_y == 0)
        {
            if (diff_x < 0)
            {
                index = 6;
                diff_x++;
            }
            else if (diff_y < 0)
            {
                index = 4;
                diff_y++;
            }
            else if (diff_x > 0)
            {
                index = 2;
                diff_x--;
            }
            else if (diff_y > 0)
            {
                index = 0;
                diff_y--;
            }
        }
        else
        {
            if (diff_x > 0 && diff_y > 0)
            {
                index = 1;
                diff_x--;
                diff_y--;
            }
            else if (diff_x > 0 && diff_y < 0)
            {
                index = 3;
                diff_x--;
                diff_y++;
            }
            else if (diff_x < 0 && diff_y < 0)
            {
                index = 5;
                diff_x++;
                diff_y++;
            }
            else if (diff_x < 0 && diff_y > 0)
            {
                index = 7;
                diff_x++;
                diff_y--;
            }
        }

        // A single line providing the move to be made: N NE E SE S SW W or NW
        printf("%s\n", direction[index]);
    }

    return 0;
}