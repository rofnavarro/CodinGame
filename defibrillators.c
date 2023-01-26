#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct  s_node
{
    int     number;
    char    *place;
    double  lon;
    double  lat;
    double  d;
}   t_node;

double    calculate(double lon_in, double lat_in, double lon, double lat)
{
    double   x;
    double   y;
    double   ret;

    x = (lon - lon_in) * cos((lat_in + lat)/2);
    y = (lat - lat_in);
    ret = sqrt(x*x + y*y) * 6371;

    return (ret);
}
char    *convert(char *array)
{
    int     i;
    char    *converter;

    converter = (char *)malloc(sizeof(char) * strlen(array));
    i = 0;
    while (array[i] != ',')
    {
        converter[i] = array[i];
        i++;
    }
    converter[i] = '.';
    i++;
    while (array[i] != '\0')
    {
        converter[i] = array[i];
        i++;
    }
    converter[i] = '\0';
    return (converter);
}

int     main()
{
    t_node  in;
    t_node  *base;
    char    *converter;
    int     i;

    char LON[51];
    scanf("%s", LON);
    converter = convert(LON);
    in.lon = atof(converter);

    char LAT[51];
    scanf("%s", LAT);
    converter = convert(LAT);
    in.lat = atof(converter);

    in.number = -1;
    in.place = NULL;
    in.d = 0;

    int N;
    scanf("%d", &N); fgetc(stdin);

    base = (t_node *)malloc(sizeof(t_node)* N);

    for (int i = 0; i < N; i++) {
        char DEFIB[257];
        scanf("%[^\n]", DEFIB); fgetc(stdin);
    }


    printf("%f\n", in.lon);
    printf("%f\n", in.lat);

    return 0;
}