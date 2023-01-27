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

    converter = (char *)malloc(sizeof(char) * strlen(array) + 1);
    i = 0;
    while (array[i] != ',' && array[i])
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
    converter[strlen(array) + 1] = '\0';
    return (converter);
}

void    parse(char *in, t_node *node)
{
    int     i;
    int     j;
    int     size;
    char    *tmp;

    size = strlen(in) + 1;
    tmp = (char *)malloc(sizeof(char) * size);
    tmp[size] = '\0';
    i = 0;
    while(in[i] != ';' && i < size)
    {
        tmp[i] = in[i];
        i++;
    }
    tmp[i] = '\0';
    node->number = atoi(tmp);
    i++;
    j = 0;
    while(in[i] != ';' && i < size)
    {
        tmp[j] = in[i];
        i++;
        j++;
    }
    tmp[j] = '\0';
    i++;
    node->place = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
    node->place[strlen(tmp) + 1] = '\0';
    strcpy(node->place, tmp);
    j = 1;
    tmp = strrchr(in, ';');
    while (tmp[j])
    {
        tmp[j - 1] = tmp[j];
        j++;
    }
    tmp[j] = '\0';
    tmp = convert(tmp);
    node->lat = atof(tmp);
    while (in[i] != '\0')
    {
        if (in[i] == ';' && in[i-1] == ';')
                break;
        i++;
    }
    i++;
    free(tmp);
    tmp = (char *)malloc(sizeof(char) * i);
    tmp[i] = '\0';
    j = 0;
    while (in[i + 2] != ',')
    {
        tmp[j] = in[i];
        i++;
        j++;
    }
    tmp = convert(tmp);
    node->lon = atof(tmp);
}

int     main()
{
    t_node  in;
    t_node  *base;
    char    *converter;
    int     i;

    char LON[51];
    scanf("%s", LON);
    converter = (char *)malloc(sizeof(char) * strlen(LON) + 1);
    converter = convert(LON);
    in.lon = atof(converter);
    free(converter);
    char LAT[51];
    scanf("%s", LAT);
    converter = (char *)malloc(sizeof(char) * strlen(LAT) + 1);
    converter = convert(LAT);
    in.lat = atof(converter);
    free(converter);
    in.number = -1;
    in.place = NULL;
    in.d = 0;

    int N;
    scanf("%d", &N); fgetc(stdin);

    base = (t_node *)malloc(sizeof(t_node)* N);

    for (i = 0; i < N; i++) {
        char DEFIB[257];
        scanf("%[^\n]", DEFIB); fgetc(stdin);
        
        parse(DEFIB, &base[i]);
        base[i].d = calculate(in.lon, in.lat, base[i].lon, base[i].lat);
        //printf("%f\n", base[i].d);
    }
    i = 1;
    while(i < N)
    {
        if (base[i - 1].d <= base[i].d)
            in.number = i - 1;
        i++;
    }

    printf("%s\n", base[in.number - 1].place); 
    return 0;
}