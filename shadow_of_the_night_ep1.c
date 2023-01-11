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
    // width of the building.
    int W;
    // height of the building.
    int H;
    scanf("%d%d", &W, &H);
    // maximum number of turns before game over.
    int N;
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);

    int x1 = 0;
    int y1 = 0;
    int x2 = W - 1;
    int y2 = H - 1;
    // game loop
    while (1) {
        // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        char bomb_dir[4];
        scanf("%s", bomb_dir);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        if (strchr(bomb_dir, 'U'))
            y2 = Y0 - 1;
        else if (strchr(bomb_dir, 'D'))
            y1 = Y0 + 1;
        if (strchr(bomb_dir, 'L'))
            x2 = X0 - 1;
        else if (strchr(bomb_dir, 'R'))
            x1 = X0 + 1;
        X0 = x1 + (x2 - x1)/ 2;
        Y0 = y1 + (y2 - y1)/ 2;

        // the location of the next window Batman should jump to.
        printf("%d %d\n", X0, Y0);
    }

    return 0;
}