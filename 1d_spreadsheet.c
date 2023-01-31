#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct  s_numbers
{
    int     x;
    int     x_ref;
    int     y;
    int     y_ref;
    int     answer;
}   t_numbers;

typedef struct  s_node
{
    char        *oper;
    t_numbers   points;
}   t_node;

void    set_ref(char *arg, int *number)
{
    int     i;
    char    *tmp;

    tmp = (char *)malloc(sizeof(char) * strlen(arg));
    
    i = 1;
    while (i < strlen(arg))
    {
        tmp[i - 1] = arg[i];
        i++;
    }
    tmp[i] = '\0';

    *number = atoi(tmp);
}

void    operation(t_node **program, int i)
{
    if (program[i]->points.x_ref == 0 && program[i]->points.y_ref == 0)
    {
        if (strcmp(program[i]->oper, "VALUE") == 0)
            program[i]->points.answer = program[i]->points.x;
        else if (strcmp(program[i]->oper, "ADD") == 0)
            program[i]->points.answer = program[i]->points.x + program[i]->points.y;
        else if (strcmp(program[i]->oper, "SUB") == 0)
            program[i]->points.answer = program[i]->points.x - program[i]->points.y;
        else if (strcmp(program[i]->oper, "MULT") == 0)
            program[i]->points.answer = program[i]->points.x * program[i]->points.y;
    }
}

int    ref_start(t_node *program)
{
    int i;

    i = 0;
    while (program[i].points.x_ref != 0 && program[i].points.y_ref != 0)
    {
        i++;
    }
    operation(&program, i);
    return (i);
}

int     solved(t_node *program, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (program[i].points.x_ref != 0 || program[i].points.y_ref != 0)
            return (1);
        i++;
    }
    return (0);
}

void    solve_ref(t_node *program, int start, int size)
{
    int i;

    while (solved(program, size) != 0)
    {
        i = 0;
        while (i < size)
        {
            if (program[i].points.x_ref != 0 && program[i].points.x == start && \
                program[start].points.x_ref == 0 && program[start].points.y_ref == 0)
            {
                program[i].points.x = program[start].points.answer;
                program[i].points.x_ref = 0;
                operation(&program, i);
            }
            if (program[i].points.y_ref != 0 && program[i].points.y == start && \
                program[start].points.x_ref == 0 && program[start].points.y_ref == 0)
            {
                program[i].points.y = program[start].points.answer;
                program[i].points.y_ref = 0;
                operation(&program, i);
            }
            operation(&program, i);
            i++;
        }
    }
}

int     main()
{
    t_node  *program;
    int     N;
    int     start;
    
    scanf("%d", &N);
    program = (t_node *)malloc(sizeof(t_node) * N);

    for (int i = 0; i < N; i++)
    {
        char operation[6];
        char arg_1[7];
        char arg_2[7];

        scanf("%s%s%s", operation, arg_1, arg_2);
        program[i].oper = strdup(operation);

        if (arg_1[0] == '_')
            program[i].points.x = 0;
        else if (arg_1[0] == '$')
        {
            program[i].points.x_ref = 1;
            set_ref(arg_1, &program[i].points.x);
        }
        else if (arg_1[0] >= '0' && arg_1[0] <= '9')
        {
            program[i].points.x = atoi(arg_1);
            program[i].points.x_ref = 0;
        }

        if (arg_2[0] == '_')
            program[i].points.y = 0;
        else if (arg_2[0] == '$')
        {
            program[i].points.y_ref = 1;
            set_ref(arg_2, &program[i].points.y);
        }
        else if (arg_2[0] >= '0' && arg_2[0] <= '9')
        {
            program[i].points.y = atoi(arg_2);
            program[i].points.y_ref = 0;
        }
    }

    start = ref_start(program);
    solve_ref(program, start, N);

    int i = 0;
    while (i < N)
    {
        printf("operacao = %s, x = %d, x ref = %d, y = %d, y ref = %d, answ = %d\n", program[i].oper, program[i].points.x, program[i].points.x_ref, program[i].points.y, program[i].points.y_ref, program[i].points.answer);
        i++;
    }
/*    for (int i = 0; i < N; i++)
    {

        printf("%d\n", program[i].points.answer);
    }
*/
    return 0;
}